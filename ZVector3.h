#pragma once

#include <iostream>

class ZVector3 {
public:
	double x, y, z;

	ZVector3(double x = 0.0, double y = 0.0, double z = 0.0)
		: x(x), y(y), z(z) {}

	ZVector3(const ZVector3& other)
		: x(other.x), y(other.y), z(other.z) {}
	// const r value reference?
	// 
	// 팩토리 패턴
	// perfect forwarding?


	// 연산자 오버로드
	ZVector3 operator+(const ZVector3& other) const {
		return ZVector3(x + other.x, y + other.y, z + other.z);
	}
	
	ZVector3 operator-(const ZVector3& other) const {
		return ZVector3(x - other.x, y - other.y, z - other.z);
	}

	double dot(const ZVector3& other) const {
		return x * other.x + y * other.y + z * other.z;
	}

	ZVector3 cross(const ZVector3& other) const {
		return ZVector3(
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x
		);
	}

	// d3d에도 math가 있다!  아무거나 사용해도 된다!
	





	// friend
	// 다른 클래스가 이 클래스의 private 멤버에 접근할 수 있도록 허용

	friend std::ostream& operator<<(std::ostream& os, const ZVector3& vec) {
		os << "ZVector3(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
		return os;
	}

	

};