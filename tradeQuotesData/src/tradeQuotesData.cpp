//============================================================================
// Name        : tradeQuotesData.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : 
// Description :
// The objective of this code is to read a supplied binary data file, search
// for a particular message type, do a trivial calculation and log the results
// to a human readable text file.
//
// The solution should be run with two command line parameters.
//    program <input file> <output file>
//
// The solution should be simple and efficient in time and space. Do no more
// work than required.
//
// The input file consists of a series of packets, <> are not included in the
// file !!.
//    <packet><packet><packet><packet>....
//
//
// A packet is defined as
//     <Packet Header><Packet Payload>
//
//
// A Packet Header is defined as
//     uint16      packet length
//     uint16      the number of update messages in the packet
//
//
// A packet payload is defined as a variable number of update messages which
// will be a mixture of Quotes and Trades
//
// A Quote is defined as
//     uint16      msg length
//     char        msg type            'Q'
//     char        symbol[5]
//     uint16      price level
//     uint16      price level size
//     int64       price level price
//     extra undefined bytes
//
// A Trade is defined as
//     uint16      msg length
//     char        msg type            'T'
//     char        symbol[5]
//     uint16      trade size
//     int64       trade price
//     extra undefined bytes
//
//
// The program should read the input file and for every trade message found,
// format text to be written to the output file with the following format.
//     <trade size * 100> <symbol> <trade price / 10000> <\n>
//
// The first 4 lines of the output file are shown below:
// 17000 CAT @ 4.72
// 70600 AA @ 6.45
// 29300 BAC @ 3.22
// 44800 CSCO @ 9.46
//
//
//
// Notes
//     The packet length field value includes itself
//     The message length field value includes itself
//     All numeric fields are in network byte order
//     The symbol field is ASCII, left justified, space filled to the right
//         if the symbol is less than 5 bytes
//
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <arpa/inet.h>
using namespace std;


uint16_t readUint16Type(ifstream &inFile, streampos &currentPos)
{
	uint16_t uint16 = 0;
	currentPos = inFile.tellg();
	inFile.read(reinterpret_cast<char *>(&uint16), sizeof(uint16));
	uint16 = ntohs(uint16);
	return uint16;
}

int64_t readInt64Type(ifstream &inFile, streampos &currentPos)
{
	int64_t int64 = 0;
	currentPos = inFile.tellg();
	inFile.read(reinterpret_cast<char *>(&int64), sizeof(int64));
	int64 = __builtin_bswap64(int64);
	return int64;
}

void rtrim(char *string)
{
	if (string != NULL)
	{
		for(int i = (strlen(string) - 1); i >= 0; i--)
			if (!isalnum(string[i]))
			{
				string[i] = 0;
			}
			else
			{
				break;
			}
	}
}

int main(int argc, char** argv) {
	if (argc != 3) {
		cerr << "Usage: " << endl;
		cerr << "   " << argv[0] << " <input file> <output file>" << endl;
		exit(1);
	}

	string inFilePath(argv[1]);
	string outFilePath(argv[2]);
	ifstream inFile(inFilePath, ios::binary | ios::in);
	ofstream outFile(outFilePath, ofstream::out);

	streampos begin, end, readPosition, messageStart, currPosition;
	streampos packetLenSum = 0;

	//Finding file size
	begin = inFile.tellg();
	inFile.seekg(0,ios::end);
	end = inFile.tellg();
	inFile.seekg(0,ios::beg);

	//A Packet Header is defined as
	//     uint16      packet length
	//     uint16      the number of update messages in the packet

	uint16_t packetLen, numberOfMessages, payloadLen;
	int packetCount = 0;

	while (packetLenSum < (end - begin)) {
		packetCount++;
		packetLen = readUint16Type(inFile, readPosition);

		if (packetLen == 0 )
			break;
		numberOfMessages = readUint16Type(inFile, readPosition);

		packetLenSum += packetLen;

		// Common in all message
		//     uint16      msg length
		//     char        msg type            'Q' / 'T'
		//     char        symbol[5]
		streampos msgLenSum = 0;
		int messageCount = 0;
		payloadLen = packetLen - (sizeof(packetLen) + sizeof(numberOfMessages));
		while (msgLenSum < payloadLen)
		{

			uint16_t msgLen;
			char msgType, symbol[6];
			messageCount++;
			msgLen = readUint16Type(inFile, readPosition);
			messageStart = readPosition;

			if(msgLen == 0)
			{
				cerr << "ERROR: Packet with 0 length - At position " << readPosition << endl;
				exit(1);
			}

			inFile.read(&msgType, sizeof(msgType));

			// When the message is of type 'Q'      | When the message is of type 'T'
			//     char        symbol[5]            |     char        symbol[5]
			//     uint16      price level          |     uint16      trade size
			//     uint16      price level size     |     int64       trade price
			//     int64       price level price    |     extra undefined bytes
			//     extra undefined bytes            |
			if (msgType == 'T')
			{
				inFile.read(symbol, 5);
				symbol[5]=0;
				rtrim(symbol);
				uint16_t tradeSize = readUint16Type(inFile, readPosition);
				int64_t tradePrice = readInt64Type(inFile, readPosition);

				// Print: <trade size * 100> <symbol> <trade price / 10000> <\n>
				// 17000 CAT @ 4.72
				// 70600 AA @ 6.45
				// 29300 BAC @ 3.22
				// 44800 CSCO @ 9.46
				outFile << tradeSize * 100 << " " << symbol << " @ " << (float)(tradePrice) / 10000 << endl;
			}
			else if (msgType == 'Q')
			{

			}
			else
			{
				cerr << "ERROR: Unknow Type at position " << readPosition << endl;
				exit(1);
			}
			currPosition = inFile.tellg();

			msgLenSum += msgLen;
			inFile.seekg(msgLen - (currPosition - messageStart), ios::cur);
		}
		inFile.seekg(packetLenSum, ios::beg);
	}
}

