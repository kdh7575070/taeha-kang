# 첫 번째 - 멋쟁이 사자처럼 X 경북대학교 SW교육센터 대구경북지역 해커톤 (우수상 수상)
2020.8.9 - 2020.9.28(해커톤당일) / 경북대학교 IT융복합관 / 멋쟁이사자처럼주관 / 우수상 수상 / 담당자 김은숙 053 - 950 - 7674 \
프로젝트 역할, 세부일정, 수상증명, 발표자료, PPT슬라이드 등에 대한 더 자세한 사항은 아래 링크에 꼼꼼하게 정리해두었습니다. \
https://www.notion.so/kangtaeha/LIKELION-X-SW-840c327fcd944ccaa5132179a309bdfc \
또한 해당 프로젝트결과를 제가 직접 배포한 주소입니다. pythonanywhere라는 서비스를 이용했고 아래 링크를 통해서 확인해보실 수 있습니다. \
해당 깃 레포지토리를 따로 첨부합니다. 하위 레포지토리에 올리려다가 push 과정에서 오류가 많아 링크를 올리는 점 양해부탁드립니다. \
https://github.com/kdh7575070/Taeha

## 웹 페이지에 대한 설명
실행 순서 : user페이지에서 회원가입 후 로그인 > 공모전 주최하기를 통해 공모전 주최 > 타인의 게시물에 아이디어 제출할 수 있음 > 본인의 게시물에 제출된 아이디어를 모아볼 수 있음 > 마이페이지에서 주최한 공모전, 좋아요를 클릭한 공모전, 제출한 아이디어를 확인 및 수정가능 > 댓글달기 및 키워드 검색, 카테고리 검색 가능 \
pythonanywhere 이라는 django 배포 툴을 이용하여 직접 배포했습니다. \
( 배포시 주요 사항을 해당 링크에 팀원들과 정리했습니다. https://www.notion.so/jacky0831/pythonAnywhere-cb77c6813442449d9f5beb2104b78ffd ) \
http://kdh7575070.pythonanywhere.com

## 코드 살펴보기


# 두 번째 - 멋쟁이 사자처럼 X 롯데그룹 전국연합 해커톤 (은상 수상)
2020.10.7 - 2020.10.25(해커톤당일) / 온라인 / 멋쟁이사자처럼주관 / 은상 수상 / 담당자 멋쟁이사자처럼 대표 \
프로젝트 역할, 세부일정, 수상증명, 발표자료, PPT슬라이드 등에 대한 더 자세한 사항은 아래 링크에 꼼꼼하게 정리해두었습니다. \
https://www.notion.so/kangtaeha/LIKELION-X-LOTTE-41f85103eac3490a9749564270b2e2ae \
해당 깃 레포지토리를 따로 첨부합니다. 하위 레포지토리에 올리려다가 push 과정에서 오류가 많아 링크를 올리는 점 양해부탁드립니다. \
https://github.com/seungdeok/webeatthelion

## 웹 페이지에 대한 설명
*test 계정* \
ID: admin@lottesuper.co.kr \
PW: admin2020 \
실행 순서 : user페이지에서 test 계정 로그인 > 배송하기 클릭 > 에코배송 선택 > 배송주소(개인 이메일)입력 > 배송완료(개인 이메일로 발송된 QR코드 확인,시스템에서 '배송완료'되었음을 확인가능) > QR스캔 페이지에서 QR코드 스캔하기 > 시스템 페이지에서 '점포대기'로 뜨는 것을 확인할 수 있음 \
Github appplication vercel을 통해 node.js코드를 간편하게 배포했습니다. \
[user] \
https://webeatthelion-userweb.vercel.app/ \
고객님이 로그인을 하고 에코 배송을 선택할 수 있는 페이지 입니다. \
[system] \
https://webeatthelion.seungdeok.vercel.app/ \
그린 캡슐의 위치 나 정보를 확인 가능한 DB 모델입니다. \
[qr scanner] \
https://webeatthelion.seungdeok.vercel.app/scan \
고객님이 그린 캡슐을 반납할 때 사용하는 QR 코드 스캔 페이지입니다.

## 코드 살펴보기
