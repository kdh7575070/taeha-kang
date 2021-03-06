# 첫 번째 - 멋쟁이 사자처럼 X 경북대학교 SW교육센터 대구경북지역 해커톤 (우수상 수상)
2020.8.9 - 2020.9.28(해커톤당일) / 경북대학교 IT융복합관 / 멋쟁이사자처럼주관 / 우수상 수상 / 담당자 김은숙 053 - 950 - 7674 \
프로젝트 역할, 세부일정, 수상증명, 발표자료, PPT슬라이드 등에 대한 더 자세한 사항은 [이 노션 링크](https://www.notion.so/kangtaeha/LIKELION-X-SW-840c327fcd944ccaa5132179a309bdfc)에 꼼꼼하게 정리해두었습니다. \
[해당 깃 레포지토리](https://github.com/kdh7575070/Taeha)를 따로 링크합니다. 하위 레포지토리에 올리려다가 push 과정에서 오류가 많아 링크를 올리는 점 양해부탁드립니다.

## 웹 페이지에 대한 설명
<img src="https://user-images.githubusercontent.com/67677983/99930892-09f00000-2d96-11eb-9fcb-234fced26507.jpg" width="800">

소상공인 공모전 플랫폼 웹사이트로 아이디어가 필요한 소상공인들이 작성한 다양한 형태의 게시물에 대학생들이 아디이어를 제출할 수 있는 플랫폼입니다. 코드는 CRUD 위주로 구성되었습니다.\
*pythonanywhere 이라는 django 배포 툴을 이용하여 제가 직접 서버에 배포했습니다. http://kdh7575070.pythonanywhere.com \
배포시 주요 사항을 [해당 노션 링크](https://www.notion.so/jacky0831/pythonAnywhere-cb77c6813442449d9f5beb2104b78ffd)에 팀원들과 정리했습니다.*

### 실행 순서
[페이지 접속](https://www.notion.so/jacky0831/pythonAnywhere-cb77c6813442449d9f5beb2104b78ffd) > user페이지에서 회원가입 후 로그인 > 공모전 주최하기를 통해 공모전 주최 > 타인의 게시물에 아이디어 제출할 수 있음 > 본인의 게시물에 제출된 아이디어를 모아볼 수 있음 > 마이페이지에서 주최한 공모전, 좋아요를 클릭한 공모전, 제출한 아이디어를 확인 및 수정가능 > 댓글달기 및 키워드 검색, 카테고리 검색 가능

### 코드 살펴보기
contest/template : 주요 html 모음\
-- base(nav바 및 주요 컨테이너), create-(작성화면), edit-(수정하면), -Post(공모전관련), -Idea(아이디어관련), -Page(마이페이지Segments) -- \
account/template : 로그인 회원가입 관련 html 모음\
*구체적인 코드에 대한 설명은 이곳에 담기는 너무 길어 인터뷰때 말씀드릴 수 있습니다.*

# 
# 두 번째 - 멋쟁이 사자처럼 X 롯데그룹 전국연합 해커톤 (은상 수상)
2020.10.7 - 2020.10.25(해커톤당일) / 온라인 / 멋쟁이사자처럼주관 / 은상 수상 / 담당자 멋쟁이사자처럼 대표 \
프로젝트 역할, 세부일정, 수상증명, 발표자료, PPT슬라이드 등에 대한 더 자세한 사항은 [이 노션 링크](https://www.notion.so/kangtaeha/LIKELION-X-LOTTE-41f85103eac3490a9749564270b2e2ae)에 꼼꼼하게 정리해두었습니다. \
[해당 깃 레포지토리](https://github.com/seungdeok/webeatthelion)를 따로 링크합니다. 하위 레포지토리에 올리려다가 push 과정에서 오류가 많아 링크를 올리는 점 양해부탁드립니다.

## 웹 페이지에 대한 설명
<img src="https://user-images.githubusercontent.com/67677983/99930925-22f8b100-2d96-11eb-93f2-d9b3595a0294.PNG" width="800">

고객이 택배를 주문하고, 주문한 택배를 QR코드를 인식해 반납하며, 물자 관리 현황을 시스템페이지로 확인하는 세 개의 web application 구현하였습니다.\
*Github appplication vercel을 통해 node.js코드를 간편하게 배포했습니다.\
[user](https://webeatthelion-userweb.vercel.app/) : 고객님이 로그인을 하고 에코 배송을 선택할 수 있는 페이지 입니다. \
[system](https://webeatthelion.seungdeok.vercel.app/) : 택배박스의 위치 나 정보를 확인 가능한 DB 모델입니다. \
[qr scanner](https://webeatthelion.seungdeok.vercel.app/scan) : 고객님이 택배박스를 반납할 때 사용하는 QR 코드 스캔 페이지입니다.*

### 실행 순서
*[test 계정 - ID: admin@lottesuper.co.kr / PW: admin2020*]\
[user](https://webeatthelion-userweb.vercel.app/) 페이지에서 test 계정 로그인 > 배송하기 클릭 > 에코배송 선택 > 배송주소(개인 이메일)입력 > 배송완료(개인 이메일로 발송된 QR코드 확인,시스템에서 '배송완료'되었음을 확인가능) > [qr scanner](https://webeatthelion.seungdeok.vercel.app/scan) 페이지에서 QR코드 스캔하기 > [user](https://webeatthelion-userweb.vercel.app/mypage) 마이페이지에서 포인트 반납택배개수 증가 확인 > [system](https://webeatthelion.seungdeok.vercel.app/) 페이지에서 '점포대기'로 뜨는 것을 확인

### 코드 살펴보기
lotte-hackathon/pages/index.js : system 화면에 관련된 프론트, 백엔드 코드입니다. \
lotte-hackathon/utils : qr코드 인식에 관한 api가 담겨있어 lotte-hackathon/pages/scan/index.js 의 scanner 화면과 연동되는 코드입니다.\
lotte-hackathon/styles : css 작업이 이루어지는 공간입니다.\
lotte-hackathon-user/pages/index.js : 유저(로그인 및 마이페이지) 화면에 관련된 프론트, 백엔드 코드입니다.\
*구체적인 코드에 대한 설명은 이곳에 담기는 너무 길어 인터뷰때 말씀드릴 수 있습니다.*

#
# 세 번째 - 산호세주립대학 실리콘밸리 소프트웨어개발 수업 및 해커톤 (Outstanding Effort상)
2020.7.20 - 2020.8.14 / 산호세주립대학 / 담당자 IT4호관 이은주 010 - 7407 - 9480 \
프로젝트 역할, 세부일정, 수상증명, 발표자료, PPT슬라이드 등에 대한 더 자세한 사항은 [이 노션 링크](https://www.notion.so/kangtaeha/SJSU-Silicon-Valley-SW-Project-a68a7515cb4c4f349c793f87e15657d0)에 꼼꼼하게 정리해두었습니다. \
[해당 깃 레포지토리](https://github.com/moonmola/MBTIclub)를 따로 링크합니다. 하위 레포지토리에 올리려다가 push 과정에서 오류가 많아 링크를 올리는 점 양해부탁드립니다.

## 어플리케이션에 대한 설명
[![Video Label](http://img.youtube.com/vi/uLR1RNqJ1Mw/0.jpg)](https://youtu.be/AZLe6kdm4Lo)\
*이미지를 클릭하시면 동영상이 등장합니다.*\
MBTI에 관심이 많은 젊은 층을 타겟으로 한 커뮤니티 플랫폼 앱으로 로그인은 구글 API를 통해 구현했고, 카카오톡 공유하기 기능의 API, 채팅 관련 API를 사용했으며, \
메인 서비스는 총 다섯가지 탭(1. 홈, 2. 추천, 3. 게시판, 4. 알림메시지와 채팅, 5. 마이페이지)으로 구성됩니다.

## 코드 살펴보기
### 제가 구현한 [4번 탭- 알람메세지](https://github.com/moonmola/MBTIclub/blob/master/app/src/main/java/com/example/mbticlub/Frag4.java)에 대한 리뷰
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        view = inflater.inflate(R.layout.frag4,container,false);

        ViewPager vp = view.findViewById(R.id.kviewpager);
        VPAdapter adapter = new VPAdapter(getFragmentManager());
        vp.setAdapter(adapter);

        TabLayout tab = view.findViewById(R.id.tab);
        tab.setupWithViewPager(vp);

        ArrayList<Integer> images = new ArrayList<Integer>();
        images.add(R.drawable.ic_not);
        images.add(R.drawable.ic_cha);

        for(int i=0; i<2; i++) tab.getTabAt(i).setIcon(images.get(i));

        return view;
    }
    // Activity가 처음 실행될 때 호출되는 함수로 VPAdapter를 통해 두개의 Fragment(내부의 또 다른 탭)와 연결됨
### 4번 탭 안의 [첫번째 탭](https://github.com/moonmola/MBTIclub/blob/master/app/src/main/java/com/example/mbticlub/BlankFragment.java)에 대한 리뷰
    board_list = (ListView) view.findViewById(R.id.board_list);

        List<String> board_data = new ArrayList<>();
        final ArrayAdapter<String> adapter = new ArrayAdapter<>(getActivity(), R.layout.memolist_type, board_data);
        board_list.setAdapter(adapter);

        board_data.add("[Report Alert]\nYour report is under review");
        board_data.add("[Comments /Anything]\nNick : Thank you:)");
        board_data.add("[Friend Request]\nName : Open Cluster (INTJ)");
    //arraylist 배열을 만들어 그 안에 스트링 형태로 알람 메시지 리스트를 만들기
