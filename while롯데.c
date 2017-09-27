#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main()
{
		int spec = 0;														// 구분
		int age = 0;														// 나이
		int howmany = 0;													// 몇장?
		int woodae = 0;														// 우대사항
		int total = 0;														// 총액
		int ticket = 0;														// 권종
		int price = 0;														// 계산전 가격
		int person = 0;														// 나이 구분
		int magicpass_five = 150; 											// 매직패스 파이브 수량
		int magicpass_free = 50;  											// 매직패스 프리 수량
		int wheel = 0;														// 장애인 수
		int freturn = 0;													// 돌아가는 용도
		int normal = 0;														// 비장애인 선발용
		int nodis = 0;														// 할인 비적용
		int devide = 0;
		int dis = 0;
		printf("롯 데 월 드 티 켓 발 권 체 계\n");
		while (1)
		{

			printf("===============================================================\n");
			while (ticket < 1 || ticket > 2)
			{
				printf("권종을 선택하세요.\n");
				printf("1. 자유 이용권\n2. 입장권\n");
				scanf("%d", &ticket);

				switch (ticket)
				{
				case 1:
					printf("'자유 이용권' 선택\n");
					break;
				case 2:
					printf("'입장권' 선택\n");
					break;
				}
			}
			printf("%d", ticket);
			printf("===============================================================\n");
			while (spec < 1 || spec > 3)
			{
				printf("티켓 구분을 선택하세요.\n");
				printf("1. 1일권\n2. After4\n3. After7 (입장권 일 경우)\n");
				scanf("%d", &spec);
				switch (spec)
				{
				case 1:
					printf("'1일권' 선택\n");
					break;
				case 2:
					printf("'After4 선택\n");
					break;
				case 3:
					if ((ticket == 1) && (spec == 3))
					{
						printf("'After7 선택_자유이용권은 선택 불가\n");
						spec = 0;
						continue;
					}
					else if (ticket == 2)
						printf("'After7 선택\n");
				}
			}
			printf("%d", spec);


			/*-------------------------------- 티켓 구분 선택 코너 -----------------------------------*/
			printf("===============================================================\n");
			printf("65 세 이상 및 3세 미만은 베이비 입니다\n");
			printf("3 ~  12	세 까지는 어린이 입니다\n");				//		티 켓 구 분			|	   권 종 구 분		|		 나 이 구 분		 |
			printf("13 ~ 18	세 까지는 청소년 입니다.\n");				// 자유이용권 : ticket = 1	| 1일권  : spec = 1		| 노인, 베이비 : person = 0	 |
			printf("18 ~ 64	세 까지는 어린이 입니다\n");				// 입  장  권 : ticket = 2	| Aftef4 : spec = 2		| 어   린   이 : person = 1  |
																// 매직5 종권 : ticket = 3	| After7 : spec = 3		| 청   소   년 : person = 2  |
			printf("나이를 입력하세요.\n");
			scanf("%d", &age);											// 매직프리권 : ticket = 4  |						|   어    른   : person = 3	 |
			if (age >= 65)
				person = 1;	// 노인
			else if ((age > 0) && (age < 3))
				person = 0; // 베이비
			else if ((age >= 3) && (age < 13))
				person = 1; // 어린이
			else if ((age >= 13) && (age < 19))
				person = 2; // 청소년
			else if ((age >= 19) && (age < 65))
				person = 3; // 어른
			else if (age <= 0)
			{
				printf("잘못 입력하셨습니다");
			}

			printf("'%d' 세 입니다.\n", age);

			if ((ticket == 1) && (spec == 1) && (person == 0))
				price = 13000;
			else if ((ticket == 1) && (spec == 2) && (person == 0))
				price = 13000;// 요금 그리고 애기들도 베이비요금
			else if ((ticket == 1) && (spec == 1) && (person == 3))						/* 		 티 켓 구 분			|	   권 종 구 분		|		 나 이 구 분		 | */
				price = 52000;															/*	// 자유이용권 : ticket = 1	| 1일권  : spec = 1		| 베   이   비 : person = 0	 | */
			else if ((ticket == 1) && (spec == 2) && (person == 3))						/*	// 입  장  권 : ticket = 2	| Aftef4 : spec = 2		| 노인, 어린이 : person = 1  | */
				price = 41000;															/*	// 매직5 종권 : ticket = 3	| After7 : spec = 3		| 청   소   년 : person = 2  | */
			else if ((ticket == 2) && (spec == 1) && (person == 3))						/*	// 매직프리권 : ticket = 4  |						|   어    른   : person = 3	 | */
				price = 36000;
			else if ((ticket == 2) && (spec == 2) && (person == 3))
				price = 30000;
			else if ((ticket == 2) && (spec == 3) && (person == 3))
				price = 18000;//어른요금표
			else if ((ticket == 1) && (spec == 1) && (person == 2))
				price = 45000;
			else if ((ticket == 1) && (spec == 2) && (person == 2))
				price = 36000;
			else if ((ticket == 2) && (spec == 1) && (person == 2))
				price = 32000;
			else if ((ticket == 2) && (spec == 2) && (person == 2))
				price = 27000;
			else if ((ticket == 2) && (spec == 3) && (person == 2))
				price = 16000;//청소년 요금표
			else if ((ticket == 1) && (spec == 1) && (person == 1))
				price = 41000;
			else if ((ticket == 1) && (spec == 2) && (person == 1))
				price = 32000;
			else if ((ticket == 2) && (spec == 1) && (person == 1))
				price = 29000;
			else if ((ticket == 2) && (spec == 2) && (person == 1))
				price = 24000;
			else if ((ticket == 2) && (spec == 3) && (person == 1))
				price = 14000;//어린이 요금표

			/*-------------------------------- 나이      선택 코너 -----------------------------------*/
			printf("===============================================================\n");
			printf("몇장을 출력하시겠습니까?\n");
			scanf("%d", &howmany);
			printf("'%d' 장을 출력합니다\n", howmany);
			printf("===============================================================\n");
			while (woodae > 1 || woodae < 3)
			{
				printf("우대사항을 선택하세요.\n");
				printf("1. 없음\n2. 장애인\n3. 국가유공자\n");
				scanf("%d", &woodae);
				switch (woodae)													// 우대요금
				{																// 없음			woodae = 1  / 1
				case 1:															// 장애인		woodae = 2	/ 7
					printf("'1. 없음'\n");										// 유공자		woodae = 3	/ 5
					woodae = 1;
					total = 1 * howmany * price;
					break;
				case 2:
					woodae = 7;
					printf("2. 장애인, 장애인 인원수 선택\n");
					scanf("%d", &wheel);
					normal = howmany - wheel;
					nodis = howmany - wheel * 2;;
					if (wheel < 0)
					{
						printf("잘못 입력 하셨습니다\n");
					}
					else if (howmany < wheel)
					{
						printf("총 인원보다 클 수 없습니다.\n");
					}
					else if (nodis <= 0)
					{
						total = (price * woodae * howmany) / 10;
						printf("%d 명", wheel);
					}
					else if (nodis > 0)
					{
						total = (nodis * price) + (2 * wheel * woodae * price) / 10;
						printf("%d 명", wheel);
					}
					break;
				case 3:
					woodae = 5;
					printf("3. 국가유공자, 유공자 인원수 선택\n");
					scanf("%d", &wheel);
					normal = howmany - wheel;
					nodis = howmany - wheel * 2;
					if (wheel < 0)
					{
						printf("잘못 입력 하셨습니다\n");
					}
					else if (howmany < wheel)
					{
						printf("총 인원보다 클 수 없습니다.\n");
					}
					else if (nodis <= 0)
					{
						total = (price * woodae * howmany) / 10;
						printf("%d 명\n", wheel);
					}
					else if (nodis > 0)
					{
						total = (nodis * price) + (2 * wheel * woodae * price) / 10;
						printf("%d 명\n", wheel);
						printf("%d", total);
					}
					break;
				default:
					printf("'잘못된 선택 입니다.\n");
				}
			}
			/*-------------------------------- 우대 사항 선택 코너 -----------------------------------*/
			printf("==============================================================================\n");
			printf("가격은 %d 원 입니다.\n", total);
			printf("감사합니다.\n");
			printf("===================================롯데월드===================================\n");
			if (ticket == 1)
				printf("자유이용권\t");
			else if (ticket == 2)
				printf("입장권\t");
			switch (spec)
			{
			case 1:
				printf("1일권\t");
				break;
			case 2:
				printf("After4\t");
				break;
			case 3:
				printf("After7\t");
				break;
			}
			switch (person)
			{
			case 0:
				printf("노인,베이비\t");
				break;
			case 1:
				printf("어린이\t");
				break;
			case 2:
				printf("청소년\t");
				break;
			case 3:
				printf("성인\t");
				break;
			}
			printf("장수 : %d\t", howmany);
			if (woodae == 1)
				printf("없음\t");
			else if (woodae == 7)
				printf("장애인 %d 인\t", wheel);
			else if (woodae == 5)
				printf("국가유공자 %d 인\t", wheel);
			printf(" %d\n\n\n", total);
			printf("==============================================================================\n");
			printf("처음으로 돌아갑니다.\n");
		}
	getchar();
	return 0;
	}