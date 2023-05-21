/*
 * yupkituk.h
 *      Author: 20181316080 이도형
 *
 */

#ifndef YUPKITUK_H_
#define YUPKITUK_H_
#include <vector>
#include <string>

void mainscreen(int &c_num);   // 메인 화면
void setmenu(int &c_num);	   // 메뉴 설정
void setmenu_side(int &c_num); // 메뉴 설정에서 사이드메뉴(튀김류, 면 or 비빔밥) 선택

class Menu
{
public:
	std::string name;	// 메뉴 이름
	unsigned int price; // 메뉴 가격

	Menu() {}
	Menu(const std::string& n, unsigned int p) : name(n), price(p) {}
	virtual ~Menu() {}
};

class Cart
{
protected:
	static std::vector<Menu> Cartlist; // 장바구니 목록
public:
	void addcart(std::string a_name, unsigned int a_price, int &c_num); // 장바구니에 메뉴 추가(사용자로부터 메뉴 이름, 가격을 입력받아 저장함)
	void erasecart(int &c_num);											// 장바구니에서 메뉴 삭제(사용자로부터 메뉴 이름, 가격, 목록 인덱스를 입력받아 삭제함)
	virtual ~Cart() {}												// 가상 소멸자
	void deleteoncart(int choice, int &c_num);							// 장바구니에서 삭제(사용자로부터 메뉴를 선택받아 삭제함)
	void resultshow(int c_num, int totalprice);							// 주문 결과 출력
	friend void setmenu(int &c_num);									// setmenu 함수에서 Cartlist에 접근할 수 있도록 함
};

class Maindish : public Cart
{
private:
	static const std::vector<Menu> Maindishlist;

public:
	Maindish() : Cart() {}
	virtual ~Maindish() {};
	void spicyselect(int &c_num, int level); // 매운 정도 선택(사용자로부터 메뉴 이름을 입력받아 해당 메뉴를 매운 정도에 맞게 설정함)
	void mainmenu(int &c_num);				 // 주 메뉴 화면
	void setmenu_main(int &c_num);			 // 메뉴 설정에서 주 메뉴
	void setmenu_chicken(int &c_num);		 // 메뉴 설정에서 꼬치어묵
	void show_main();						 // 주 메뉴 전체 출력
};

class Side : public Cart
{
private:
	static const std::vector<Menu> Sidelist;

public:
	Side() : Cart() {}
	virtual ~Side() {}
	void sidemenu(int &c_num); // 사이드 메뉴 화면
	void show_side();		   // 사이드 메뉴 전체 출력
};

class Topping : public Cart
{
private:
	static const std::vector<Menu> Toppinglist;

public:
	Topping() : Cart() {}
	virtual ~Topping() {}
	void toppingmenu(int &c_num);		  // 토핑 메뉴 화면
	void show_top();					  // 토핑 메뉴 전체 출력
	friend void setmenu_side(int &c_num); // setmenu_side에서 toppinglist에 접근할 수 있도록 함
};

#endif /* YUPKITUK_H_ */
