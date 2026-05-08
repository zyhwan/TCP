#pragma once
#ifndef __PACKET_H__
#define __PACKET_H__

enum class PacketType
{
	Plus = 0,
	Minus,
	Multiply,
	Divide,
	Remainder,
	Max //패킷의 최대 크기
};

#define TotalHeaderSize			4

typedef struct PacketHeader
{
	unsigned short Size;
	unsigned short Code;
} PACKETHEADER;


#endif //__PACKET_H__
