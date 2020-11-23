# 실습 과제에 대한 간단한 소개
     
### 1장
ds1(포인터) \
ds2(포인터) \
ds3(성능평가) \
ds4(성능측정)
### 2장
ds5(동적할당 / 구조체)\
ds6(다항식 / 희소행렬)
### 3장
ds7(정적스택 / 정적선형큐 / 동적스택 / 동적선형큐)\
ds8(미로 / 동적환형큐) \
ds9(후위표기연산 / 중위->후위변환)
### 4장
ds10([int]연결리스트 / 연결스택 / 연결큐 / [char]연결리스트)\
ds11(다항식연결리스트 / 다항식환형연결리스트 / 이중연결리스트)
### 5장
ds12([stack]깊이연결 / [queue]넓이연결) \
ds13([stack]후위이진트리의3fix순회 / [stack]반복문순회,[queue]level순회) \
ds14(명제식의중위-후위변환 / [stack]후위이진트리변환-중위순회 / [stack]후위이진트리변환-Post형조합평가) \
ds15(힙정렬 / 이진트리정렬) ds16(위너트리정렬)
### 6장
ds17(인접연결리스트 / 멀티연결리스트) \
ds18(dfs / bfs / connected)
### 7장
ds19(삽입정렬 / 퀵정렬) \
ds20(합병정렬 / 합병정렬재귀) \
ds21(힙정렬 / 기수정렬)
### 8장
ds22(해싱-[char]선형조사)\
ds23(해싱-[int]랜덤조사 / 해싱-[char]체이닝)

## 코드 뜯어보기
# 1장 - ds4 성능측정코드 - 소팅알고리즘의 성능을 층정해보는 코드

     for (n=0; n<=2000; n += step){
		long repetitions = 0;
		start = clock();

		do
		{
			repetitions++;

			for(i=0; i<n;i++)
				a[i] = n-1;

			sort(a,n);

		}while (clock()-start<1000); //1초동안반복해서돌림
		
		duration = ((double)(clock() - start))/CLOCKS_PER_SEC; //총걸린시간 - 1초 돌렸으니까 다 일초나오겠지
		duration /= repetitions; 

reptitions(몇번 반복했는지)으로 나누면 1번에 몇초 걸렸는지 평균이 나옴

		printf("%6ld   %9ld   %f\n", n, repetitions, duration);
		fprintf(fpOut, "%6ld   %9ld   %f\n", n, repetitions, duration);
		if (n == 100) step = 100;
최종결과
