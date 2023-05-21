/*
 * yupkishow.cpp
 *      Author: 20181316080 이도형
 *
 */
#include "yupkituk.h"
#include <iostream>
#include <string>
#include <vector>

void Cart::erasecart(int &c_num)
{
home:
	std::cout << "\n" << "--주문한 메뉴--\n";
	int pricetotal{0};
	for (int i = 0; i < c_num; i++) // for문을 통해 장바구니에 담긴 내용을 출력합니다.
	{
		std::cout << "[" << i + 1 << "]" << Cartlist[i].name << " : " << Cartlist[i].price << "원\n";
		pricetotal += Cartlist[i].price;
	}
	std::cout << "총 가격: " << pricetotal << "원\n"; // 총가격을 출력합니다.
	std::cout << "제거할 메뉴의 번호를 입력해주세요 (세트메뉴 중 하나 제거시 전체가 제거됩니다.)\n";
	std::cout << "[0] - 메뉴 선택 종료\n"
			  << "[-1] - 다시 메뉴 선택\n";
	int choice{};
	std::cout << "---세트메뉴 제거시 제일 위에 메뉴를 제거해주세요---------\n";
	std::cout << "---메뉴를 제거하면 그것을 따르는 토핑은 자동 제거됩니다.---\n";
	std::cout << "번호 입력:";
	std::cin >> choice;
	if (std::cin.fail())
	{
		std::cout << "\n\n----다시 입력해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
	} // 잘못된 입력(숫자 이외의 문자)가 들어오면 다시 입력받도록 합니다.
	else if (choice == 0)
		resultshow(c_num, pricetotal); // 0 -> 메뉴 삭제 완료
	else if (choice == -1)
	{}									 // -1 -> 함수종료(mainscreen으로 돌아감)
	else if (choice >= 1 && choice <= c_num) // 1~벡터 크기까지의 범위 -> 특정 메뉴 삭제
	{
		deleteoncart(choice, c_num); // 메뉴 삭제
		goto home;
	}
	else
	{
		std::cout << "\n\n----다시 입력해주세요----\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		goto home;
	}
}

void Cart::deleteoncart(int choice, int &c_num)
{
	int fin = Cartlist.size();
	if (Cartlist[choice].name[2] == '-')
	{
		int i{};
		for(i = choice; i < fin; i++)
		{
			Cartlist[i].name.assign(Cartlist[i+1].name);
			Cartlist[i].price = Cartlist[i+1].price;
		}
	    Cartlist.erase(Cartlist.begin() + i);
	    c_num--;
	}
	else if (Cartlist[choice].price == 0)
	{
	    int start = choice;
	    int end = choice;

	    while (start >= 0 && Cartlist[start].price > 10000)
	    {
	        start--; // 시작 인덱스 왼쪽으로 이동
	    }
	    while (end < Cartlist.size() && Cartlist[end].price != 0 && Cartlist[end].name[2] != '-')
	    {
	        end++; // 끝 인덱스 오른쪽으로 이동
	    }

	    int numToDelete = end - start - 1; // 삭제해야 할 원소 개수

	    if (numToDelete > 0)
	    {
	    	int i{};
	    	for(i=start; i<numToDelete; i++)
	    	{
	    		if(i + numToDelete > Cartlist.size())
	    		{
	    			Cartlist.erase(Cartlist.begin() + i, Cartlist.begin() + Cartlist.size());
	    			break;
	    		}
	    		Cartlist[i].name.assign(Cartlist[i+numToDelete].name);
	    		Cartlist[i].price = Cartlist[i+numToDelete].price;
	    	}
	        c_num -= numToDelete;
	    }
	}

	/*
	int a{1};
	int b{0};

	if (Cartlist[choice - 1].price > 10000 && Cartlist[choice].name[2] == '-') // (특별 메뉴)이 1개이상, 특별 메뉴+1이 0개이면,
																			   // 특별 메뉴 삭제(전체가 단품 메뉴로 바뀌거나), 그리고 특별 메뉴는 맨 위로 올라갑니다.
	{
		b++; // b를 1 증가시킵니다.
		while (1)
		{
			if (Cartlist[choice + b].name[2] == '-')
				b++; // 특별 메뉴가 연속으로 여러 개일 경우 1개씩 건너뛰도록 합니다.
			else
				break;
		}
	}

	if (Cartlist[choice - 1 + b].price != 0 && Cartlist[choice + b].price == 0) // (특별 메뉴)가 0개이고, (특별 메뉴+1)이 0이면, 다음 (단품 메뉴+1)까지만 삭제
																				// 여기서 b는 전체를 포함한 카운터입니다.
	{
		while (1)
		{
			if ((Cartlist[choice + a - 1 + b].price == 0 && Cartlist[choice + a + b].price != 0) || (choice + a + b == c_num))
				break; // (단품 메뉴의 가격이 0이고) - (특별 메뉴)까지의 범위가 (0) - (0이 아닌 가격)으로 구분되어 있기 때문입니다.
			else
				a++; // 아니면 a를 1 증가시킵니다.
		}
		a++; // 이후 (단품 메뉴1) - (단품 메뉴2) - (다른 특별메뉴)들의 경우를 대비하여 가격표시 등의 작업을 더 진행하기 위해 더해줍니다.
	}

	a += b; // (특별 메뉴 개수) + (일반 메뉴)

	for (int j = choice - 1; j < c_num - a; j++)
	    {
	        Cartlist[j].name.assign(Cartlist[j + a].name);
	        Cartlist[j].price = Cartlist[j + a].price;
	    }
	    c_num -= a;

	    std::cout << "\n선택한 메뉴 "<< Cartlist[choice-1].name <<"을(를) 제거했습니다.\n";
	    std::cin.clear();
	    std::cin.ignore(256, '\n');
	    */
}

void Cart::resultshow(int c_num, int totalprice)
{
	std::cout << "\n";
	for (int i = 0; i < c_num; i++)
		std::cout << Cartlist[i].name << " - " << Cartlist[i].price << "\n";
	std::cout << "총 가격: " << totalprice << "원\n";
	return ;
}
