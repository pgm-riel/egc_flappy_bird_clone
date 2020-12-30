#include "Airplane.h"

#include <vector>
#include <iostream>
#include <math.h>

#include <Core/Engine.h>
using namespace std;



AirPlane::AirPlane()
{
}

AirPlane::~AirPlane()
{
}


Mesh * AirPlane::CreatePlane()
{
	

	vector<VertexFormat> vertices
	{
		// hull
		// upper hull
		// 1st segment upper hull
		VertexFormat(initpos + glm::vec3(0, 1, 0), glm::vec3(1, 0.29411f, 0.18039f)), // 0 
		VertexFormat(initpos + glm::vec3(-0.85f, 0.85f, 0), glm::vec3(1, 0.29411f, 0.18039f)), // 1
		VertexFormat(initpos + glm::vec3(-1, 0.5f, 0), glm::vec3(1, 0.29411f, 0.18039f)), // 2
		VertexFormat(initpos + glm::vec3(-1, 0.1f, 0), glm::vec3(1, 0.29411f, 0.18039f)), // 3

		VertexFormat(initpos + glm::vec3(0.85f, 0.85f, 0), glm::vec3(1, 0.29411f, 0.18039f)), // 4
		VertexFormat(initpos + glm::vec3(1, 0.5f, 0), glm::vec3(1, 0.29411f, 0.18039f)), // 5
		VertexFormat(initpos + glm::vec3(1, 0.1f, 0), glm::vec3(1, 0.29411f, 0.18039f)), // 6

		// 2nd segment upper hull
		VertexFormat(initpos + glm::vec3(0, 1, 1), glm::vec3(1, 0.29411f, 0.18039f)), // 7 
		VertexFormat(initpos + glm::vec3(-0.85f, 0.85f, 1), glm::vec3(1, 0.29411f, 0.18039f)), // 8
		VertexFormat(initpos + glm::vec3(-1, 0.5f, 1), glm::vec3(1, 0.29411f, 0.18039f)), // 9
		VertexFormat(initpos + glm::vec3(-1, 0.1f, 1), glm::vec3(1, 0.29411f, 0.18039f)), // 10

		VertexFormat(initpos + glm::vec3(0.85f, 0.85f, 1), glm::vec3(1, 0.29411f, 0.18039f)), // 11
		VertexFormat(initpos + glm::vec3(1, 0.5f, 1), glm::vec3(1, 0.29411f, 0.18039f)), // 12
		VertexFormat(initpos + glm::vec3(1, 0.1f, 1), glm::vec3(1, 0.29411f, 0.18039f)), // 13

		// 3rd segment upper hull
		VertexFormat(initpos + glm::vec3(0, 1, 2), glm::vec3(1, 0.29411f, 0.18039f)), // 14 
		VertexFormat(initpos + glm::vec3(-0.85f, 0.85f, 2), glm::vec3(1, 0.29411f, 0.18039f)), // 15
		VertexFormat(initpos + glm::vec3(-1, 0.5f, 2), glm::vec3(1, 0.29411f, 0.18039f)), // 16
		VertexFormat(initpos + glm::vec3(-1, 0.2f, 2), glm::vec3(1, 0.29411f, 0.18039f)), // 17

		VertexFormat(initpos + glm::vec3(0.85f, 0.85f, 2), glm::vec3(1, 0.29411f, 0.18039f)), // 18
		VertexFormat(initpos + glm::vec3(1, 0.5f, 2), glm::vec3(1, 0.29411f, 0.18039f)), // 19
		VertexFormat(initpos + glm::vec3(1, 0.2f, 2), glm::vec3(1, 0.29411f, 0.18039f)), // 20

		// 4th segment upper hull
		VertexFormat(initpos + glm::vec3(0, 1, 3), glm::vec3(1, 0.29411f, 0.18039f)), // 21
		VertexFormat(initpos + glm::vec3(-0.85f, 0.85f, 3), glm::vec3(1, 0.29411f, 0.18039f)), // 22
		VertexFormat(initpos + glm::vec3(-1, 0.5f, 3), glm::vec3(1, 0.29411f, 0.18039f)), // 23
		VertexFormat(initpos + glm::vec3(-1, 0.4f, 3), glm::vec3(1, 0.29411f, 0.18039f)), // 24

		VertexFormat(initpos + glm::vec3(0.85f, 0.85f, 3), glm::vec3(1, 0.29411f, 0.18039f)), // 25
		VertexFormat(initpos + glm::vec3(1, 0.5f, 3), glm::vec3(1, 0.29411f, 0.18039f)), // 26
		VertexFormat(initpos + glm::vec3(1, 0.4f, 3), glm::vec3(1, 0.29411f, 0.18039f)), // 27
	
		// 5th segment upper hull
		VertexFormat(initpos + glm::vec3(0, 1, 4), glm::vec3(1, 0.29411f, 0.18039f)), // 28
		VertexFormat(initpos + glm::vec3(-0.85f, 0.85f, 4), glm::vec3(1, 0.29411f, 0.18039f)), // 29
		VertexFormat(initpos + glm::vec3(-1, 0.7f, 4), glm::vec3(1, 0.29411f, 0.18039f)), // 30
		VertexFormat(initpos + glm::vec3(-1, 0.6f, 4), glm::vec3(1, 0.29411f, 0.18039f)), // 31

		VertexFormat(initpos + glm::vec3(0.85f, 0.85f, 4), glm::vec3(1, 0.29411f, 0.18039f)), // 32
		VertexFormat(initpos + glm::vec3(1, 0.7f, 4), glm::vec3(1, 0.29411f, 0.18039f)), // 33
		VertexFormat(initpos + glm::vec3(1, 0.6f, 4), glm::vec3(1, 0.29411f, 0.18039f)), // 34

		// 6th segment upper hull
		VertexFormat(initpos + glm::vec3(0, 1, 5), glm::vec3(1, 0.29411f, 0.18039f)), // 35
		VertexFormat(initpos + glm::vec3(-0.85f, 0.85f, 5), glm::vec3(1, 0.29411f, 0.18039f)), // 36
		VertexFormat(initpos + glm::vec3(-1, 0.4f, 5), glm::vec3(1, 0.29411f, 0.18039f)), // 37
		VertexFormat(initpos + glm::vec3(-1, 0.3f, 5), glm::vec3(1, 0.29411f, 0.18039f)), // 38

		VertexFormat(initpos + glm::vec3(0.85f, 0.85f, 5), glm::vec3(1, 0.29411f, 0.18039f)), // 39
		VertexFormat(initpos + glm::vec3(1, 0.4f, 5), glm::vec3(1, 0.29411f, 0.18039f)), // 40
		VertexFormat(initpos + glm::vec3(1, 0.3f, 5), glm::vec3(1, 0.29411f, 0.18039f)), // 41

		// PointsNorth
		VertexFormat(initpos + glm::vec3(0, 0.5f, 6.3f), glm::vec3(1, 0.29411f, 0.18039f)), // 42
		VertexFormat(initpos + glm::vec3(0, 0.4f, 6.2f), glm::vec3(1, 0.29411f, 0.18039f)), // 43

		// lower hull
		// 1st segment form point to back
		VertexFormat(initpos + glm::vec3(0, 0.4f, 6.2f), glm::vec3(1, 0.91372f, 0.61176f)), // 44
		VertexFormat(initpos + glm::vec3(0, 0.0f, 5), glm::vec3(1, 0.91372f, 0.61176f)), // 45
		VertexFormat(initpos + glm::vec3(-0.9f, 0.2f, 5), glm::vec3(1, 0.91372f, 0.61176f)), // 46
		VertexFormat(initpos + glm::vec3(0.9f, 0.2f, 5), glm::vec3(1, 0.91372f, 0.61176f)), // 47
		VertexFormat(initpos + glm::vec3(-1, 0.3f, 5), glm::vec3(1, 0.91372f, 0.61176f)), // 48
		VertexFormat(initpos + glm::vec3(1, 0.3f, 5), glm::vec3(1, 0.91372f, 0.61176f)), // 49

		// 2nd segment
		VertexFormat(initpos + glm::vec3(0, 0.0f, 4), glm::vec3(1, 0.91372f, 0.61176f)), // 50
		VertexFormat(initpos + glm::vec3(-1, 0.2f, 4), glm::vec3(1, 0.91372f, 0.61176f)), // 51
		VertexFormat(initpos + glm::vec3(1, 0.2f, 4), glm::vec3(1, 0.91372f, 0.61176f)), // 52
		VertexFormat(initpos + glm::vec3(-1, 0.6f, 4), glm::vec3(1, 0.91372f, 0.61176f)), // 53
		VertexFormat(initpos + glm::vec3(1, 0.6f, 4), glm::vec3(1, 0.91372f, 0.61176f)), // 54

		// 3rd segment
		VertexFormat(initpos + glm::vec3(0, -0.05f, 3), glm::vec3(1, 0.91372f, 0.61176f)), // 55
		VertexFormat(initpos + glm::vec3(-1, 0.2f, 3), glm::vec3(1, 0.91372f, 0.61176f)), // 56
		VertexFormat(initpos + glm::vec3(1, 0.2f, 3), glm::vec3(1, 0.91372f, 0.61176f)), // 57
		VertexFormat(initpos + glm::vec3(-1, 0.4f, 3), glm::vec3(1, 0.91372f, 0.61176f)), // 58
		VertexFormat(initpos + glm::vec3(1, 0.4f, 3), glm::vec3(1, 0.91372f, 0.61176f)), // 59

		// 4th segment
		VertexFormat(initpos + glm::vec3(0, -0.1f, 2), glm::vec3(1, 0.91372f, 0.61176f)), // 60
		VertexFormat(initpos + glm::vec3(-1, 0.2f, 2), glm::vec3(1, 0.91372f, 0.61176f)), // 61
		VertexFormat(initpos + glm::vec3(1, 0.2f, 2), glm::vec3(1, 0.91372f, 0.61176f)), // 62

		// 5th segment
		VertexFormat(initpos + glm::vec3(0, -0.1f, 1), glm::vec3(1, 0.91372f, 0.61176f)), // 63
		VertexFormat(initpos + glm::vec3(-1, 0.1f, 1), glm::vec3(1, 0.91372f, 0.61176f)), // 64
		VertexFormat(initpos + glm::vec3(1, 0.1f, 1), glm::vec3(1, 0.91372f, 0.61176f)), // 65

		// 6th segment
		VertexFormat(initpos + glm::vec3(0, -0.1f, 0), glm::vec3(1, 0.91372f, 0.61176f)), // 66
		VertexFormat(initpos + glm::vec3(-1, 0.1f, 0), glm::vec3(1, 0.91372f, 0.61176f)), // 67
		VertexFormat(initpos + glm::vec3(1, 0.1f, 0), glm::vec3(1, 0.91372f, 0.61176f)), // 68

		// tail
		// upper tail
		// 1st segment upper tail
		VertexFormat(initpos + glm::vec3(0, 1, -0.5f), glm::vec3(1, 0.29411f, 0.18039f)), // 69
		VertexFormat(initpos + glm::vec3(-0.85f, 0.85f, -0.5f), glm::vec3(1, 0.29411f, 0.18039f)), // 70
		VertexFormat(initpos + glm::vec3(-1, 0.6f, -0.5f), glm::vec3(1, 0.29411f, 0.18039f)), // 71
		VertexFormat(initpos + glm::vec3(0.85f, 0.85f, -0.5f), glm::vec3(1, 0.29411f, 0.18039f)), // 72
		VertexFormat(initpos + glm::vec3(1, 0.6f, -0.5f), glm::vec3(1, 0.29411f, 0.18039f)), // 73
		
		VertexFormat(initpos + glm::vec3(-1, 0.4f, 0), glm::vec3(1, 0.29411f, 0.18039f)), // 74
		VertexFormat(initpos + glm::vec3(1, 0.4f, 0), glm::vec3(1, 0.29411f, 0.18039f)), // 75
		
		// 2nd segment upper tail
		VertexFormat(initpos + glm::vec3(-0.65f, 0.85f, -0.7f), glm::vec3(1, 0.29411f, 0.18039f)), // 76
		VertexFormat(initpos + glm::vec3(-1, 0.7f, -0.7f), glm::vec3(1, 0.29411f, 0.18039f)), // 77
		VertexFormat(initpos + glm::vec3(0.65f, 0.85f, -0.7f), glm::vec3(1, 0.29411f, 0.18039f)), // 78
		VertexFormat(initpos + glm::vec3(1, 0.7f, -0.7f), glm::vec3(1, 0.29411f, 0.18039f)), // 79

		// 3rd segment upper tail
		VertexFormat(initpos + glm::vec3(0, 1.1f, -1), glm::vec3(1, 0.29411f, 0.18039f)), // 80
		VertexFormat(initpos + glm::vec3(-0.65f, 0.85f, -1), glm::vec3(1, 0.29411f, 0.18039f)), // 81
		VertexFormat(initpos + glm::vec3(-1, 0.8f, -1), glm::vec3(1, 0.29411f, 0.18039f)), // 82
		VertexFormat(initpos + glm::vec3(0.65f, 0.85f, -1), glm::vec3(1, 0.29411f, 0.18039f)), // 83
		VertexFormat(initpos + glm::vec3(1, 0.8f, -1), glm::vec3(1, 0.29411f, 0.18039f)), // 84

		// 4th segment upper tail
		VertexFormat(initpos + glm::vec3(0, 1.1f, -3), glm::vec3(1, 0.29411f, 0.18039f)), // 85
		VertexFormat(initpos + glm::vec3(-0.35f, 0.98f, -3), glm::vec3(1, 0.29411f, 0.18039f)), // 86
		VertexFormat(initpos + glm::vec3(-0.4f, 0.94f, -3), glm::vec3(1, 0.29411f, 0.18039f)), // 87
		VertexFormat(initpos + glm::vec3(0.35f, 0.98f, -3), glm::vec3(1, 0.29411f, 0.18039f)), // 88
		VertexFormat(initpos + glm::vec3(0.4f, 0.94f, -3), glm::vec3(1, 0.29411f, 0.18039f)), // 89

		// 5th segment upper tail
		VertexFormat(initpos + glm::vec3(0, 1.1f, -3.5f), glm::vec3(1, 0.29411f, 0.18039f)), // 90
		VertexFormat(initpos + glm::vec3(-0.25f, 0.98f, -3.5f), glm::vec3(1, 0.29411f, 0.18039f)), // 91
		VertexFormat(initpos + glm::vec3(-0.3f, 0.94f, -3.5f), glm::vec3(1, 0.29411f, 0.18039f)), // 92
		VertexFormat(initpos + glm::vec3(0.25f, 0.98f, -3.5f), glm::vec3(1, 0.29411f, 0.18039f)), // 93
		VertexFormat(initpos + glm::vec3(0.3f, 0.94f, -3.5f), glm::vec3(1, 0.29411f, 0.18039f)), // 94

		//PointFort
		VertexFormat(initpos + glm::vec3(0, 0.9, -5.5), glm::vec3(1, 0.29411f, 0.18039f)), // 95

		// lower tail
		// 1st segment lower tail
		VertexFormat(initpos + glm::vec3(0, 0.9f, -3.5f), glm::vec3(1, 0.91372f, 0.61176f)), // 96
		VertexFormat(initpos + glm::vec3(-0.3f, 0.94f, -3.5f), glm::vec3(1, 0.91372f, 0.61176f)), // 97
		VertexFormat(initpos + glm::vec3(0.3f, 0.94f, -3.5f), glm::vec3(1, 0.91372f, 0.61176f)), // 98
		VertexFormat(initpos + glm::vec3(0, 0.9, -5.5), glm::vec3(1, 0.91372f, 0.61176f)), // 99
		// 2nd segment
		VertexFormat(initpos + glm::vec3(-1, 0.4f, 0), glm::vec3(1, 0.91372f, 0.61176f)), // 100
		VertexFormat(initpos + glm::vec3(1, 0.4f, 0), glm::vec3(1, 0.91372f, 0.61176f)), // 101
		VertexFormat(initpos + glm::vec3(-1, 0.6f, -0.5f), glm::vec3(1, 0.91372f, 0.61176f)), // 102			
		VertexFormat(initpos + glm::vec3(1, 0.6f, -0.5f), glm::vec3(1, 0.91372f, 0.61176f)), // 103
		VertexFormat(initpos + glm::vec3(-1, 0.7f, -0.7f), glm::vec3(1, 0.91372f, 0.61176f)), // 104
		VertexFormat(initpos + glm::vec3(1, 0.7f, -0.7f), glm::vec3(1, 0.91372f, 0.61176f)), // 105
		VertexFormat(initpos + glm::vec3(-1, 0.8f, -1), glm::vec3(1, 0.91372f, 0.61176f)), // 106
		VertexFormat(initpos + glm::vec3(1, 0.8f, -1), glm::vec3(1, 0.91372f, 0.61176f)), // 107
		VertexFormat(initpos + glm::vec3(-0.4f, 0.94f, -3), glm::vec3(1, 0.91372f, 0.61176f)), // 108
		VertexFormat(initpos + glm::vec3(0.4f, 0.94f, -3), glm::vec3(1, 0.91372f, 0.61176f)), // 109

		// seat
		VertexFormat(initpos + glm::vec3(0, 1, -0.5f), glm::vec3(0.31372, 0.32156, 0.32941)), // 110
		VertexFormat(initpos + glm::vec3(-0.65f, 0.85f, -0.7f), glm::vec3(0.31372, 0.32156, 0.32941)), // 111
		VertexFormat(initpos + glm::vec3(0.65f, 0.85f, -0.7f), glm::vec3(0.31372, 0.32156, 0.32941)), // 112
		VertexFormat(initpos + glm::vec3(0, 1.1f, -1), glm::vec3(0.31372, 0.32156, 0.32941)), // 113
		VertexFormat(initpos + glm::vec3(0, 0.6f, -0.9f), glm::vec3(0, 0, 0)), // 114
		VertexFormat(initpos + glm::vec3(0, 0.6f, -0.2f), glm::vec3(0, 0, 0)), // 115
		
		// flappers
		VertexFormat(initpos + glm::vec3(0, 1.1f, -3.5f), glm::vec3(1, 0.29411f, 0.18039f)), // 116
		VertexFormat(initpos + glm::vec3(-0.25f, 0.98f, -3.5f), glm::vec3(1, 0.29411f, 0.18039f)), // 117
		VertexFormat(initpos + glm::vec3(0.25f, 0.98f, -3.5f), glm::vec3(1, 0.29411f, 0.18039f)), // 118
		VertexFormat(initpos + glm::vec3(0, 2.1f, -4.5f), glm::vec3(1, 0.29411f, 0.18039f)), // 119
		VertexFormat(initpos + glm::vec3(0, 2.2f, -5.2f), glm::vec3(1, 0.29411f, 0.18039f)), // 120
		VertexFormat(initpos + glm::vec3(-0.1, 1.15f, -5.2f), glm::vec3(0.8, 0.19411f, 0.18039f)), // 121
		VertexFormat(initpos + glm::vec3(0.1, 1.15f, -5.2f), glm::vec3(0.8, 0.19411f, 0.18039f)), // 122
		VertexFormat(initpos + glm::vec3(0, 2.1f, -5.3f), glm::vec3(0.8, 0.19411f, 0.18039f)), // 123
		VertexFormat(initpos + glm::vec3(0, 1.15f, -5.2f), glm::vec3(0.8, 0.19411f, 0.18039f)), // 124
		VertexFormat(initpos + glm::vec3(-2, 0.98f, -3.7f), glm::vec3(1, 0.29411f, 0.18039f)), // 125
		VertexFormat(initpos + glm::vec3(2, 0.98f, -3.7f), glm::vec3(1, 0.29411f, 0.18039f)), // 126
		VertexFormat(initpos + glm::vec3(-2, 0.98f, -4.5), glm::vec3(1, 0.29411f, 0.18039f)), // 127
		VertexFormat(initpos + glm::vec3(2, 0.98f, -4.5), glm::vec3(1, 0.29411f, 0.18039f)), // 128

		// wings
		// 1st beam
		VertexFormat(initpos + glm::vec3(-0.4, 0.6625, 0), glm::vec3(1, 0.39411f, 0.18039f)), // 129
		VertexFormat(initpos + glm::vec3(-0.4, 0.6625, 0.1), glm::vec3(1, 0.39411f, 0.18039f)), // 130
		VertexFormat(initpos + glm::vec3(-0.45, 0.6525, 0), glm::vec3(1, 0.39411f, 0.18039f)), // 131
		VertexFormat(initpos + glm::vec3(-0.45, 0.6525, 0.1), glm::vec3(1, 0.39411f, 0.18039f)), // 132
		VertexFormat(initpos + glm::vec3(-0.5, 1.9, 0), glm::vec3(1, 0.39411f, 0.18039f)), // 133
		VertexFormat(initpos + glm::vec3(-0.5, 1.9, 0.1), glm::vec3(1, 0.39411f, 0.18039f)), // 134
		VertexFormat(initpos + glm::vec3(-0.55, 1.9, 0), glm::vec3(1, 0.39411f, 0.18039f)), // 135
		VertexFormat(initpos + glm::vec3(-0.55, 1.9, 0.1), glm::vec3(1, 0.39411f, 0.18039f)), // 136
		// 2nd beam
		VertexFormat(initpos + glm::vec3(0.4, 0.6625, 0), glm::vec3(1, 0.39411f, 0.18039f)), // 137
		VertexFormat(initpos + glm::vec3(0.4, 0.6625, 0.1), glm::vec3(1, 0.39411f, 0.18039f)), // 138
		VertexFormat(initpos + glm::vec3(0.45, 0.6525, 0), glm::vec3(1, 0.39411f, 0.18039f)), // 139
		VertexFormat(initpos + glm::vec3(0.45, 0.6525, 0.1), glm::vec3(1, 0.39411f, 0.18039f)), // 140
		VertexFormat(initpos + glm::vec3(0.5, 1.9, 0), glm::vec3(1, 0.39411f, 0.18039f)), // 141
		VertexFormat(initpos + glm::vec3(0.5, 1.9, 0.1), glm::vec3(1, 0.39411f, 0.18039f)), // 142
		VertexFormat(initpos + glm::vec3(0.55, 1.9, 0), glm::vec3(1, 0.39411f, 0.18039f)), // 143
		VertexFormat(initpos + glm::vec3(0.55, 1.9, 0.1), glm::vec3(1, 0.39411f, 0.18039f)), // 144
		// 3rd beam
		VertexFormat(initpos + glm::vec3(-0.4, 0.6625, 0.5), glm::vec3(1, 0.39411f, 0.18039f)), // 145
		VertexFormat(initpos + glm::vec3(-0.4, 0.6625, 0.6), glm::vec3(1, 0.39411f, 0.18039f)), // 146
		VertexFormat(initpos + glm::vec3(-0.45, 0.6525, 0.5), glm::vec3(1, 0.39411f, 0.18039f)), // 147
		VertexFormat(initpos + glm::vec3(-0.45, 0.6525, 0.6), glm::vec3(1, 0.39411f, 0.18039f)), // 148
		VertexFormat(initpos + glm::vec3(-0.5, 1.9, 0.5), glm::vec3(1, 0.39411f, 0.18039f)), // 149
		VertexFormat(initpos + glm::vec3(-0.5, 1.9, 0.6), glm::vec3(1, 0.39411f, 0.18039f)), // 150
		VertexFormat(initpos + glm::vec3(-0.55, 1.9, 0.5), glm::vec3(1, 0.39411f, 0.18039f)), // 151
		VertexFormat(initpos + glm::vec3(-0.55, 1.9, 0.6), glm::vec3(1, 0.39411f, 0.18039f)), // 152
		// 4th beam
		VertexFormat(initpos + glm::vec3(0.4, 0.6625, 0.5), glm::vec3(1, 0.39411f, 0.18039f)), // 153
		VertexFormat(initpos + glm::vec3(0.4, 0.6625, 0.6), glm::vec3(1, 0.39411f, 0.18039f)), // 154
		VertexFormat(initpos + glm::vec3(0.45, 0.6525, 0.5), glm::vec3(1, 0.39411f, 0.18039f)), // 155
		VertexFormat(initpos + glm::vec3(0.45, 0.6525, 0.6), glm::vec3(1, 0.39411f, 0.18039f)), // 156
		VertexFormat(initpos + glm::vec3(0.5, 1.9, 0.5), glm::vec3(1, 0.39411f, 0.18039f)), // 157
		VertexFormat(initpos + glm::vec3(0.5, 1.9, 0.6), glm::vec3(1, 0.39411f, 0.18039f)), // 158
		VertexFormat(initpos + glm::vec3(0.55, 1.9, 0.5), glm::vec3(1, 0.39411f, 0.18039f)), // 159
		VertexFormat(initpos + glm::vec3(0.55, 1.9, 0.6), glm::vec3(1, 0.39411f, 0.18039f)), // 160
		// wing

		VertexFormat(initpos + glm::vec3(-3, 1.6, 1.2), glm::vec3(1, 0.29411f, 0.18039f)), // 161
		VertexFormat(initpos + glm::vec3(3, 1.6, 1.2), glm::vec3(1, 0.29411f, 0.18039f)), // 162
		VertexFormat(initpos + glm::vec3(-3.3, 1.6, -0.2), glm::vec3(1, 0.29411f, 0.18039f)), // 163
		VertexFormat(initpos + glm::vec3(3.3, 1.6, -0.2), glm::vec3(1, 0.29411f, 0.18039f)), // 164

		VertexFormat(initpos + glm::vec3(-3.5, 1.6, 0.9), glm::vec3(1, 0.29411f, 0.18039f)), // 165
		VertexFormat(initpos + glm::vec3(3.5, 1.6, 0.9), glm::vec3(1, 0.29411f, 0.18039f)), // 166
		VertexFormat(initpos + glm::vec3(-3.5, 1.6, 0.1), glm::vec3(1, 0.29411f, 0.18039f)), // 167
		VertexFormat(initpos + glm::vec3(3.5, 1.6, 0.1), glm::vec3(1, 0.29411f, 0.18039f)), // 168

		VertexFormat(initpos + glm::vec3(-3, 1.7, 1.1), glm::vec3(1, 0.29411f, 0.18039f)), // 169
		VertexFormat(initpos + glm::vec3(3, 1.7, 1.1), glm::vec3(1, 0.29411f, 0.18039f)), // 170
		VertexFormat(initpos + glm::vec3(-3.3, 1.7, -0.2), glm::vec3(1, 0.29411f, 0.18039f)), // 171
		VertexFormat(initpos + glm::vec3(3.3, 1.7, -0.2), glm::vec3(1, 0.29411f, 0.18039f)), // 172

		VertexFormat(initpos + glm::vec3(-3.5, 1.7, 0.8), glm::vec3(1, 0.29411f, 0.18039f)), // 173
		VertexFormat(initpos + glm::vec3(3.5, 1.7, 0.8), glm::vec3(1, 0.29411f, 0.18039f)), // 174
		VertexFormat(initpos + glm::vec3(-3.5, 1.7, 0.1), glm::vec3(1, 0.29411f, 0.18039f)), // 175
		VertexFormat(initpos + glm::vec3(3.5, 1.7, 0.1), glm::vec3(1, 0.29411f, 0.18039f)), // 176

		VertexFormat(initpos + glm::vec3(-3, 1.6, 1.2), glm::vec3(1, 0.39411f, 0.18039f)), // 177
		VertexFormat(initpos + glm::vec3(3, 1.6, 1.2), glm::vec3(1, 0.39411f, 0.18039f)), // 178
		VertexFormat(initpos + glm::vec3(-3.3, 1.6, -0.2), glm::vec3(1, 0.39411f, 0.18039f)), // 179
		VertexFormat(initpos + glm::vec3(3.3, 1.6, -0.2), glm::vec3(1, 0.39411f, 0.18039f)), // 180

		VertexFormat(initpos + glm::vec3(-3.5, 1.6, 0.9), glm::vec3(1, 0.39411f, 0.18039f)), // 181
		VertexFormat(initpos + glm::vec3(3.5, 1.6, 0.9), glm::vec3(1, 0.39411f, 0.18039f)), // 182
		VertexFormat(initpos + glm::vec3(-3.5, 1.6, 0.1), glm::vec3(1, 0.39411f, 0.18039f)), // 183
		VertexFormat(initpos + glm::vec3(3.5, 1.6, 0.1), glm::vec3(1, 0.39411f, 0.18039f)), // 184

		VertexFormat(initpos + glm::vec3(-3, 1.7, 1.1), glm::vec3(1, 0.39411f, 0.18039f)), // 185
		VertexFormat(initpos + glm::vec3(3, 1.7, 1.1), glm::vec3(1, 0.39411f, 0.18039f)), // 186
		VertexFormat(initpos + glm::vec3(-3.3, 1.7, -0.2), glm::vec3(1, 0.39411f, 0.18039f)), // 187
		VertexFormat(initpos + glm::vec3(3.3, 1.7, -0.2), glm::vec3(1, 0.39411f, 0.18039f)), // 188

		VertexFormat(initpos + glm::vec3(-3.5, 1.7, 0.8), glm::vec3(1, 0.39411f, 0.18039f)), // 189
		VertexFormat(initpos + glm::vec3(3.5, 1.7, 0.8), glm::vec3(1, 0.39411f, 0.18039f)), // 190
		VertexFormat(initpos + glm::vec3(-3.5, 1.7, 0.1), glm::vec3(1, 0.39411f, 0.18039f)), // 191
		VertexFormat(initpos + glm::vec3(3.5, 1.7, 0.1), glm::vec3(1, 0.39411f, 0.18039f)), // 192
		// engine
		VertexFormat(initpos + glm::vec3(-0.55, 1.9, 1.3), glm::vec3(1, 0.39411f, 0.18039f)), // 193
		VertexFormat(initpos + glm::vec3(-0.55, 1.9, 0), glm::vec3(1, 0.39411f, 0.18039f)), // 194
		VertexFormat(initpos + glm::vec3(0.55, 1.9, 1.3), glm::vec3(1, 0.39411f, 0.18039f)), // 195
		VertexFormat(initpos + glm::vec3(0.55, 1.9, 0), glm::vec3(1, 0.39411f, 0.18039f)), // 196

		VertexFormat(initpos + glm::vec3(-0.55, 2.2, 1.2), glm::vec3(1, 0.39411f, 0.18039f)), // 197
		VertexFormat(initpos + glm::vec3(-0.55, 2.2, 0.2), glm::vec3(1, 0.39411f, 0.18039f)), // 198
		VertexFormat(initpos + glm::vec3(0.55, 2.2, 1.2), glm::vec3(1, 0.39411f, 0.18039f)), // 199
		VertexFormat(initpos + glm::vec3(0.55, 2.2, 0.2), glm::vec3(1, 0.39411f, 0.18039f)), // 200
		VertexFormat(initpos + glm::vec3(-0.55, 2.1, 0), glm::vec3(1, 0.39411f, 0.18039f)), // 201
		VertexFormat(initpos + glm::vec3(0.55, 2.1, 0), glm::vec3(1, 0.39411f, 0.18039f)), // 202

		VertexFormat(initpos + glm::vec3(0, 2.1, 1.25), glm::vec3(0.6, 0.59411f, 0.58039f)), // 203
		VertexFormat(initpos + glm::vec3(0, 2, 1.26), glm::vec3(0.6, 0.59411f, 0.58039f)), // 204
		VertexFormat(initpos + glm::vec3(-0.1, 2.05, 1.255), glm::vec3(0.6, 0.59411f, 0.58039f)), // 205
		VertexFormat(initpos + glm::vec3(0.1, 2.05, 1.255), glm::vec3(0.6, 0.59411f, 0.58039f)), // 206
		VertexFormat(initpos + glm::vec3(0, 2.05, 1.5), glm::vec3(0.6, 0.59411f, 0.58039f)), // 207



	};

	vector<unsigned short> indices = 
	{
		// upper hull
		// 1
		0, 7, 1,
		7, 1, 8,

		1, 8, 2,
		8, 2, 9,

		2, 9, 3,
		9, 3, 10,

		0, 7, 4,
		7, 4, 11,

		4, 11, 5,
		11, 5, 12,

		5, 12, 6,
		12, 6, 13,

		// 2
		7, 14, 8,
		14, 8, 15,

		8, 15, 9,
		15, 9, 16,

		9, 16, 10,
		16, 10, 17,

		7, 14, 11,
		14, 11, 18,

		11, 18, 12,
		18, 12, 19,

		12, 19, 13,
		19, 13, 20,

		//3
		14, 21, 15,
		21, 15, 22,

		15, 22, 16,
		22, 16, 23,

		16, 23, 17,
		23, 17, 24,

		14, 21, 18,
		21, 18, 25,

		18, 25, 19,
		25, 19, 26,

		19, 26, 20,
		26, 20, 27,

		//4
		21, 28, 22,
		28, 22, 29,

		22, 29, 23,
		29, 23, 30,

		23, 30, 24,
		30, 24, 31,

		21, 28, 25,
		28, 25, 32,

		25, 32, 26,
		32, 26, 33,

		26, 33, 27,
		33, 27, 34,

		//5
		28, 35, 29,
		35, 29, 36,

		29, 36, 30,
		36, 30, 37,

		30, 37, 31,
		37, 31, 38,

		28, 35, 32,
		35, 32, 39,

		32, 39, 33,
		39, 33, 40,

		33, 40, 34,
		40, 34, 41,
		
		//point
		35, 36, 42,
		36, 37, 42,
		37, 38, 42,
		35, 39, 42,
		39, 40, 42,
		40, 41, 42,
		42, 43, 41,
		42, 43, 38,

		//lower hull
		// 1
		44, 45, 46,
		44, 45, 47,
		44, 46, 48,
		44, 47, 49,
		// 2
		45, 46, 50,
		46, 50, 51,

		45, 47, 50,
		47, 50, 52,

		46, 48, 51,
		48, 51, 53,

		47, 49, 52,
		49, 52, 54,
		// 3
		50, 51, 55,
		51, 55, 56,

		50, 52, 55,
		52, 55, 57,

		51, 53, 56,
		53, 56, 58,

		52, 54, 57,
		54, 57, 59,
		// 4
		55, 56, 60,
		56, 60, 61,

		55, 57, 60,
		57, 60, 62,

		56, 61, 58,
		57, 62, 59,
		// 5
		60, 61, 63,
		61, 63, 64,

		60, 62, 63,
		62, 63, 65,
		// 6
		63, 64, 66,
		64, 66, 67,

		63, 65, 66,
		65, 66, 68,

		//tail
		// 1
		0, 1, 69,
		1, 69, 70,

		1, 74, 70,
		74, 70, 71,

		0, 4, 69,
		4, 69, 72,

		4, 75, 72,
		75, 72, 73,

		1, 74, 2,
		4, 75, 5,
		// 2
		69, 70, 76,
		70, 76, 77,
		70, 71, 77,

		69, 72, 78,
		72, 78, 79,
		72, 73, 79,
		// 3
		76, 80, 81,
		76, 81, 82,
		76, 77, 82,

		78, 80, 83,
		78, 83, 84,
		78, 79, 84,
		// 4
		80, 85, 81,
		81, 85, 86,

		81, 86, 87,
		81, 82, 87,

		80, 85, 83,
		83, 85, 88,

		83, 88, 89,
		83, 84, 89,
		// 5
		85, 90, 86,
		86, 90, 91,

		86, 91, 92,
		86, 87, 92,

		85, 90, 88,
		88, 90, 93,

		88, 93, 94,
		88, 89, 94,
		// 6
		95, 90, 91,
		95, 91, 92,
		95, 90, 93,
		95, 93, 94,

		// lower tail
		// 1
		66, 96, 67,
		67, 96, 97,

		66, 68, 96,
		68, 96, 98,

		96, 97, 99,
		96, 98, 99,
		// 2
		97, 100, 67,
		98, 101, 68,   

		97, 100, 102,
		98, 101, 103,
		97, 102, 104,
		98, 103, 105,
		97, 104, 106,
		98, 105, 107,
		97, 106, 108,
		98, 107, 109,

		// seat
		110, 115, 111,
		110, 115, 112,
		113, 114, 111,
		113, 114, 112,
		114, 115, 111,
		114, 115, 112,
		
		// flappers
		116, 117, 119,
		116, 118, 119,
		119, 120, 117,
		119, 120, 118,
		120, 121, 117,
		120, 122, 118,
		116, 120, 121,
		120, 123, 121,
		120, 123, 122,
		123, 124, 121,
		123, 124, 122,
		117, 127, 125,
		118, 128, 126,
		117, 121, 127,
		118, 122, 128,

		//wings
		129, 130, 134,
		129, 133, 134,
		130, 132, 134,
		130, 132, 136,
		132, 131, 136,
		131, 136, 135,
		129, 131, 133,
		131, 133, 135,

		137, 138, 142,
		137, 141, 142,
		138, 140, 142,
		138, 140, 144,
		140, 139, 144,
		139, 144, 143,
		137, 139, 141,
		139, 141, 143,

		145, 146, 150,
		145, 149, 150,
		146, 148, 150,
		146, 148, 152,
		148, 147, 152,
		147, 152, 151,
		145, 147, 149,
		147, 149, 151,

		153, 154, 158,
		154, 157, 158,
		154, 156, 158,
		154, 156, 160,
		156, 155, 160,
		155, 160, 159,
		153, 155, 157,
		155, 157, 159,

		161, 162, 163,
		162, 163, 164,

		161, 165, 167,
		161, 167, 163,

		162, 166, 168, 
		162, 168, 164,

		169, 170, 171,
		170, 171, 172,

		169, 173, 175,
		169, 175, 171,

		170, 174, 176,
		170, 176, 172,

		186, 178, 177,
		177, 186, 185,
		177, 185, 189,
		177, 189, 181,
		181, 189, 191,
		181, 191, 183,
		183, 191, 187,
		183, 179, 187,
		179, 187, 180,
		180, 187, 188,
		180, 188, 184,
		184, 188, 192,
		184, 192, 190,
		184, 190, 182,
		182, 190, 186,
		182, 186, 178,
		//engine
		193, 194, 195,
		194, 195, 196,
		197, 198, 199,
		198, 199, 200,
		193, 195, 197,
		195, 197, 199,
		194, 196, 201,
		196, 201, 202,
		198, 200, 201,
		200, 201, 202,

		193, 197, 194,
		194, 197, 198,
		194, 198, 201,

		195, 199, 196,
		196, 199, 200,
		196, 198, 202,

		207, 203, 205,
		207, 205, 204,
		207, 204, 206,
		207, 206, 203,
	};



	Mesh * plane_mesh = AirPlane::CreateMesh("plane_mesh", vertices, indices);

	return plane_mesh;



}

Mesh * AirPlane::CreatePropeller()
{
	vector<VertexFormat> vertices
	{
		VertexFormat(initpos + glm::vec3(0, 2.05, 1.5), glm::vec3(0.6, 0.59411f, 0.58039f)), // 0
		VertexFormat(initpos + glm::vec3(-0.1, 2.9f, 1.5f), glm::vec3(0.6, 0.59411f, 0.58039f)), // 1
		VertexFormat(initpos + glm::vec3(0.1, 2.9f, 1.5f), glm::vec3(0.6, 0.59411f, 0.58039f)), // 2
		VertexFormat(initpos + glm::vec3(-0.1, 1.1f, 1.5f), glm::vec3(0.6, 0.59411f, 0.58039f)), // 3
		VertexFormat(initpos + glm::vec3(0.1, 1.1f, 1.5f), glm::vec3(0.6, 0.59411f, 0.58039f)), // 4

		VertexFormat(initpos + glm::vec3(-0.1, 2.9f, 1.7f), glm::vec3(0.6, 0.59411f, 0.58039f)), // 5
		VertexFormat(initpos + glm::vec3(0.1, 2.9f, 1.7f), glm::vec3(0.6, 0.59411f, 0.58039f)), // 6
		VertexFormat(initpos + glm::vec3(-0.1, 1.1f, 1.7f), glm::vec3(0.6, 0.59411f, 0.58039f)), // 7
		VertexFormat(initpos + glm::vec3(0.1, 1.1f, 1.7f), glm::vec3(0.6, 0.59411f, 0.58039f)), // 8
	};

	vector<unsigned short> indices =
	{
		0, 1, 2,
		0, 3, 4,

		0, 5, 6,
		0, 7, 8,

		0, 1, 5,
		0, 2, 6,

		0, 3, 7,
		0, 4, 8,

		1, 2, 5,
		2, 5, 6,

		3, 4, 7,
		4, 7, 8,
	};

	Mesh * propeller_mesh = AirPlane::CreateMesh("propeller_mesh", vertices, indices);

	return propeller_mesh;


}

Mesh * AirPlane::CreateMesh(const char * name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices)
{
	
	unsigned int VAO = 0;
	// TODO: Create the VAO and bind it
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// TODO: Create the VBO and bind it
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// TODO: Send vertices data into the VBO buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	// TODO: Crete the IBO and bind it
	unsigned int IBO;
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	// TODO: Send indices data into the IBO buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

	// ========================================================================
	// This section describes how the GPU Shader Vertex Shader program receives data

	// set vertex position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

	// set vertex normal attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

	// set texture coordinate attribute
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

	// set vertex color attribute
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));
	// ========================================================================

	// Unbind the VAO
	glBindVertexArray(0);

	// Check for OpenGL errors
	CheckOpenGLError();

	// Mesh information is saved into a Mesh object
	meshes_airplane[name] = new Mesh(name);
	meshes_airplane[name]->InitFromBuffer(VAO, static_cast<unsigned short>(indices.size()));
	meshes_airplane[name]->vertices = vertices;
	meshes_airplane[name]->indices = indices;
	return meshes_airplane[name];

}
