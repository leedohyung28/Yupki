/*
 * yupkiadd.cpp
 *      Author: 20181316080 이도형
 */

#include "yupkituk.h"
#include <vector>
#include <string>
#include <iostream>

const std::vector<Menu> Topping::Toppinglist = {
		    {"---(토핑)치즈", 3000},
		    {"---(토핑)햄", 1000},
		    {"---(토핑)베이컨", 3000},
		    {"---(토핑)떡추가", 1000},
		    {"---(토핑)오뎅추가", 1000},
		    {"---(토핑)퐁당치즈만두", 2000},
		    {"---(토핑)우동사리", 2000},
		    {"---(토핑)당면사리", 2000},
		    {"---(토핑)중국당면", 2500},
		    {"---(토핑)계란", 1500},
		    {"---(토핑)메추리알", 1000}
		};


const std::vector<Menu> Maindish::Maindishlist = {
	    {"엽기떡볶이", 14000},
	    {"엽기오뎅", 14000},
	    {"엽기반반", 14000},
	    {"엽기닭볶음탕", 24000},
	    {"2인 엽기떡볶이", 9000},
	    {"엽기로제떡볶이", 16000},
	    {"엽기로제오뎅", 16000},
	    {"엽기로제반반", 16000},
	    {"엽기 무뼈닭발", 15000},
	    {"엽기 국물닭발", 15000},
	    {"엽기 통닭발", 14000},
	    {"엽기 오돌뼈", 14000},
	    {"엽기 닭날개", 14000}
	};

const std::vector<Menu> Side::Sidelist = {
		    {"주먹김밥", 2000},
		    {"계란찜", 2000},
		    {"계란야채죽", 5000},
		    {"치즈죽", 6000},
		    {"오뎅탕", 6000},
		    {"공기밥", 1000},
		    {"모둠튀김", 2000},
		    {"김말이", 2000},
		    {"야채튀김", 1000},
		    {"튀김만두", 2000},
		    {"바삭치즈만두", 2000},
		    {"엽도그", 2000},
		    {"순대", 3000},
		    {"버터꿀봉", 11000},
		    {"고추맵봉", 11000},
		    {"음료(유산균)", 1000}
		};

std::vector<Menu> Cart::Cartlist;

void Cart::addcart(std::string a_name, unsigned int a_price, int &c_num)
{
	Cartlist.insert(Cartlist.begin() + c_num, Menu{a_name, a_price});
	c_num++;
}

void mainscreen(int &c_num)
{
home:
	Maindish m;
	Side s;
	Cart c;
	int choice{};
	std::cout << "\n" << "--메인메뉴--\n";
	std::cout << "[0] 주문 완료(결정/삭제)\n"
			  << "[1] 메인 메뉴 선택\n"
			  << "[2] 사이드 메뉴 선택\n"
			  << "[3] 세트 메뉴 선택\n"
			  << "입력을 입력하세요: ";
	std::cin >> choice;
	if (std::cin.fail())
	{
		std::cout << "\n\n----다시 입력해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
	}
	switch (choice)
	{
	case 1:
		m.mainmenu(c_num);
		std::cin.clear();
		std::cin.ignore(256, '\n');
		break;
	case 2:
		s.sidemenu(c_num);
		std::cin.clear();
		std::cin.ignore(256, '\n');
		break;
	case 3:
		setmenu(c_num);
		std::cin.clear();
		std::cin.ignore(256, '\n');
		break;
	case 0:
		c.erasecart(c_num);
		std::cin.clear();
		std::cin.ignore(256, '\n');
		break;
	default:
		std::cout << "\n\n----다시 선택해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		break;
	}
	goto home;
}

void Maindish::mainmenu(int &c_num)
{
home:
	Topping t;
	show_main();
	std::cout << "[0] - 메인 메뉴 선택 X\n";
	std::cout << "메인 메뉴를 선택해주세요: ";
	int choice{};
	std::cin >> choice;
	if (std::cin.fail())
	{
		std::cout << "\n\n----다시 선택해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
	}
	switch (choice)
	{
	case 1:
	case 2:
	case 3:
	case 4:
		addcart(Maindishlist[choice - 1].name, Maindishlist[choice - 1].price, c_num);
		spicyselect(c_num, 1);
		std::cout << Maindishlist[choice - 1].name << "를(을) 선택하였습니다.\n\n";
		t.toppingmenu(c_num);
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
		break;
	case 5:
		addcart(Maindishlist[choice - 1].name, Maindishlist[choice - 1].price, c_num);
		spicyselect(c_num, 2);
		std::cout << Maindishlist[choice - 1].name << "를(을) 선택하였습니다.\n\n";
		t.toppingmenu(c_num);
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
		break;
	case 6:
	case 7:
	case 8:
		addcart(Maindishlist[choice - 1].name, Maindishlist[choice - 1].price, c_num);
		spicyselect(c_num, 3);
		std::cout << Maindishlist[choice - 1].name << "를(을) 선택하였습니다.\n\n";
		t.toppingmenu(c_num);
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
		break;
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
		addcart(Maindishlist[choice - 1].name, Maindishlist[choice - 1].price, c_num);
		std::cout << Maindishlist[choice - 1].name << "를(을) 선택하였습니다.\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
		break;
	case 0:
		break;
	default:
		std::cout << "\n\n----다시 선택해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
		break;
	}
}

void Maindish::show_main()
{
	std::cout << "\n" << "--메인 메뉴--\n";
	for (int i = 0; i < 13; i++)
		std::cout << "[" << i + 1 << "] - " << Maindishlist[i].name << " :  " << Maindishlist[i].price << "원\n";
}

void Maindish::spicyselect(int &c_num, int level)
{
home:
	int spicy{};
	switch (level)
	{
	case 1:
		std::cout << "\n---맵기를 선택해주세요.---" << '\n'
				  << "[1-착한맛]" << '\n'
				  << "[2-초보맛]" << '\n'
				  << "[3-덜매운맛]" << '\n'
				  << "[4-오리지널]" << '\n'
				  << "[5-매운맛]" << '\n';
		std::cout << "맵기 선택: ";
		std::cin >> spicy;
		if (std::cin.fail())
		{
			std::cout << "\n\n----다시 선택해주세요----\n\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			goto home;
		}
		switch (spicy)
		{
		case 1:
			Cartlist[c_num - 1].name.append("(착한맛)");
			std::cin.clear();
			std::cin.ignore(256, '\n');
			break;
		case 2:
			Cartlist[c_num - 1].name.append("(초보맛)");
			std::cin.clear();
			std::cin.ignore(256, '\n');
			break;
		case 3:
			Cartlist[c_num - 1].name.append("(덜매운맛)");
			std::cin.clear();
			std::cin.ignore(256, '\n');
			break;
		case 4:
			Cartlist[c_num - 1].name.append("(오리지널)");
			std::cin.clear();
			std::cin.ignore(256, '\n');
			break;
		case 5:
			Cartlist[c_num - 1].name.append("(매운맛)");
			std::cin.clear();
			std::cin.ignore(256, '\n');
			break;
		default:
			std::cout << "\n\n----다시 선택해주세요----\n\n";
			goto home;
			break;
		}
		break;
	case 2:
		std::cout << "\n---맵기를 선택해주세요.---" << '\n'
				  << "[1-착한맛]" << '\n'
				  << "[2-초보맛]" << '\n'
				  << "[3-덜매운맛]" << '\n'
				  << "[4-오리지널]" << '\n';
		std::cout << "맵기 선택: ";
		std::cin >> spicy;
		if (std::cin.fail())
		{
			std::cout << "\n\n-----다시 선택해주세요----\n\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			goto home;
		}
		switch (spicy)
		{
		case 1:
			Cartlist[c_num - 1].name.append("(착한맛)");
			std::cin.clear();
			std::cin.ignore(256, '\n');
			break;
		case 2:
			Cartlist[c_num - 1].name.append("(초보맛)");
			std::cin.clear();
			std::cin.ignore(256, '\n');
			break;
		case 3:
			Cartlist[c_num - 1].name.append("(덜매운맛)");
			std::cin.clear();
			std::cin.ignore(256, '\n');
			break;
		case 4:
			Cartlist[c_num - 1].name.append("(오리지널)");
			std::cin.clear();
			std::cin.ignore(256, '\n');
			break;
		default:
			std::cout << "\n\n----다시 선택해주세요----\n\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			goto home;
			break;
		}
		break;
	case 3:
		std::cout << "\n---맵기를 선택해주세요.---\n"
				  << "[1-착한맛]" << '\n'
				  << "[2-초보맛]" << '\n';
		std::cout << "맵기 선택: ";
		std::cin >> spicy;
		if (std::cin.fail())
		{
			std::cout << "\n\n----다시 선택해주세요----\n\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			goto home;
		}
		switch (spicy)
		{
		case 1:
			Cartlist[c_num - 1].name.append("(착한맛)");
			std::cin.clear();
			std::cin.ignore(256, '\n');
			break;
		case 2:
			Cartlist[c_num - 1].name.append("(초보맛)");
			std::cin.clear();
			std::cin.ignore(256, '\n');
			break;
		default:
			std::cout << "\n\n----다시 선택해주세요----\n\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			goto home;
			break;
		}
		break;
	}
}

void Side::show_side()
{
	std::cout << "\n" << "--사이드 메뉴--\n";
	for (int i = 0; i < 16; i++)
		std::cout << "[" << i + 1 << "] - " << Sidelist[i].name << " : " << Sidelist[i].price << "원\n";
}

void Side::sidemenu(int &c_num)
{
home:
	show_side();
	std::cout << "[0] - 사이드 선택 X\n";
	std::cout << "사이드메뉴를 선택해주세요 : ";
	int choice{};
	std::cin >> choice;
	if (std::cin.fail())
	{
		std::cout << "\n\n----다시 선택해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
	}

	if (choice >= 1 && choice <= 16)
	{
		addcart(Sidelist[choice - 1].name, Sidelist[choice - 1].price, c_num);
		std::cout << Sidelist[choice - 1].name << "을(를) 선택하셨습니다.\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
	}
	else if (choice == 0)
	{}
	else
	{
		std::cout << "\n\n----다시 선택해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
	}
}

void setmenu(int &c_num)
{
home:
	Maindish m;
	Cart c;
	std::cout << "\n" << "--세트 메뉴--\n";
	std::cout << "[1] - A SET : 17000\n"
			  << "[2] - B SET : 19000\n"
			  << "[3] - C SET : 21000\n"
			  << "[4] - FAMILY SET : 28000\n"
			  << "[5] - 엽기닭발 SET : 16000\n";
	std::cout << "[0] - 세트메뉴 선택 X\n";
	std::cout << "세트메뉴를 선택해주세요 : ";
	int set_add_menu{0};
	int choice{};
	int tmp{};
	std::cin >> choice;
	if (std::cin.fail())
	{
		std::cout << "\n\n----다시 선택해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
	}

	switch (choice)
	{
	case 1:
		tmp = c_num;
		m.setmenu_main(c_num);
		c.Cartlist[tmp].name.append("(A SET)");
		c.Cartlist[tmp].price = 17000;
		setmenu_side(c_num);
		std::cout << "A SET을 선택하셨습니다.\n\n";
		goto home;
		break;
	case 2:
		tmp = c_num;
		m.setmenu_main(c_num);
		c.Cartlist[tmp].name.append("(B SET)");
		c.Cartlist[tmp].price = 19000;
		setmenu_side(c_num);
		c.addcart("주먹김밥", 0, c_num);
		std::cout << "B SET을 선택하셨습니다.\n\n";
		goto home;
		break;
	case 3:
		tmp = c_num;
		m.setmenu_main(c_num);
		c.Cartlist[tmp].name.append("(C SET)");
		c.Cartlist[tmp].price = 21000;
		setmenu_side(c_num);
		c.addcart("주먹김밥", 0, c_num);
		c.addcart("당면", 0, c_num);
		std::cout << "C SET을 선택하셨습니다.\n\n";
		goto home;
		break;
	case 4:
		tmp = c_num;
		m.setmenu_main(c_num);
		m.setmenu_chicken(c_num);
		c.Cartlist[tmp].name.append("(FAMILY SET)");
		c.Cartlist[tmp].price = 28000;
		c.addcart("주먹김밥", 0, c_num);
		std::cout << "FAMILY SET을 선택하셨습니다.\n\n";
		goto home;
		break;
	case 5:
		tmp = c_num;
		m.setmenu_chicken(c_num);
		c.Cartlist[tmp].name.append("(엽기닭발 SET)");
		c.Cartlist[tmp].price = 16000;
		c.addcart("주먹김밥", 0, c_num);
		std::cout << "엽기닭발 SET을 선택하셨습니다.\n\n";
		goto home;
		break;
	case 0:
		break;
	default:
		std::cout << "\n\n----다시 입력하세요----\n\n";
		goto home;
		break;
	}
}

void Maindish::setmenu_main(int &c_num)
{
home:
	Topping t;
	int choice{};
	std::cout << "\n" << "--세트 메뉴(떡볶이)--\n";
	std::cout << "[1] - 엽기떡볶이\n"
			  << "[2] - 엽기오뎅\n"
			  << "[3] - 엽기반반\n";
	std::cout << "원하시는 번호를 선택하세요: ";
	std::cin >> choice;
	if (std::cin.fail())
	{
		std::cout << "\n\n----다시 선택해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
	}									 // 잘못된 입력 (숫자 이외의 문자)가 들어온 경우 다시 입력 받도록 함
	else if (choice >= 1 && choice <= 3) // 선택한 메뉴에 해당하는 mainmenu를 cart에 추가
	{
		addcart(Maindishlist[choice - 1].name, 0, c_num);
		spicyselect(c_num, 1);
		t.toppingmenu(c_num);
		std::cout << Maindishlist[choice - 1].name << " 을(를) 선택하셨습니다.\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	else
	{
		std::cout << "\n\n----다시 선택해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
	}
}

void setmenu_side(int &c_num)
{
home:
	Cart c;
	Topping t;
	c.addcart("모듬튀김(야채튀김1 + 김말이1 + 만두2)", 0, c_num);
	int choice{};
	std::cout << "[1] - 계란 2알\n"
			  << "[2] - 메추리알 5알\n";
	std::cout << "원하는 사이드 메뉴를 선택해주세요 : ";
	std::cin >> choice;
	if (std::cin.fail())
	{
		std::cout << "\n\n----다시 선택해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
	} // 잘못된 입력 (숫자 이외의 문자)가 들어온 경우 다시 입력 받도록 함
	switch (choice)
	{ // 선택한 음료에 따라 추가함
	case 1:
		c.addcart("계란 2알", 0, c_num);
		std::cout << "계란 2알 을 선택하셨습니다.\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		break;
	case 2:
		c.addcart("메추리알 5알", 0, c_num);
		std::cout << "메추리알 5알 을 선택하셨습니다.\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		break;
	default:
		std::cout << "\n\n----다시 선택해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
		break;
	}
}

void Maindish::setmenu_chicken(int &c_num)
{
home:
	Topping t;
	int choice{};
	std::cout << "\n" << "--세트 메뉴(닭발)--\n";
	std::cout << "[1] - 엽기 무뼈닭발\n"
			  << "[2] - 엽기 국물 닭발\n"
			  << "[3] - 엽기 통닭발\n"
			  << "[4] - 엽기 오돌뼈\n"
			  << "[5] - 엽기 닭날개\n";
	std::cout << "원하는 닭발 메뉴를 선택해주세요 : ";
	std::cin >> choice;
	if (std::cin.fail())
	{
		std::cout << "\n\n----다시 선택해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
	}									 // 잘못된 입력 (숫자 이외의 문자)가 들어온 경우 다시 입력 받도록 함
	else if (choice >= 1 && choice <= 5) // 선택한 메뉴에 해당하는 mainmenu를 cart에 추가
	{
		addcart(Maindishlist[choice + 7].name, 0, c_num);
		std::cout << Maindishlist[choice + 7].name << " 을(를) 선택하셨습니다.\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		t.toppingmenu(c_num);
	}
	else
	{
		std::cout << "\n\n----다시 선택해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
	}
}

void Topping::show_top()
{
	std::cout << "\n" << "--토핑 선택--\n";
	for (int i = 0; i < 11; i++)
		std::cout << "[" << i + 1 << "] - " << Toppinglist[i].name << " :  " << Toppinglist[i].price << "원\n";
} // for 루프를 통해 전체 토핑 메뉴 출력

void Topping::toppingmenu(int &c_num)
{
home:
	Maindish m;
	show_top();
	std::cout << "[0] - 토핑 선택 X\n";
	std::cout << "추가할 토핑의 번호를 선택하세요: ";
	int choice{};
	std::cin >> choice;
	if (std::cin.fail())
	{
		std::cout << "\n\n----다시 선택해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
	}									  // 잘못된 입력 (숫자 이외의 문자)가 들어온 경우 다시 입력 받도록 함
	else if (choice >= 1 && choice <= 11) // 1~11 -> 토핑 추가, 루프
	{
		addcart(Toppinglist[choice - 1].name, Toppinglist[choice - 1].price, c_num);
		std::cout << Toppinglist[choice - 1].name << " 을(를) 선택하셨습니다.\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
	}
	else if (choice == 0)
	{}// 0 -> 함수 종료
	else  // 그 외 -> 루프
	{
		std::cout << "\n\n----다시 선택해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
	}
}
