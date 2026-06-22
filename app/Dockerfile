FROM ubuntu:24.04
# 나쁜 점1: 앱 코드를 먼저 복사 → 코드 한 줄만 바뀌어도 아래 전부 캐시 무효
COPY . /src
WORKDIR /src
# 나쁜 점2: 무거운 빌드 의존성을 매 빌드마다 재설치 (캐시 안 탐), 단일 스테이지
RUN apt-get update && apt-get install -y g++ wget ca-certificates \
    && rm -rf /var/lib/apt/lists/*
# 나쁜 점3: 헤더를 매번 새로 받고 컴파일 (캐시 마운트 없음)
RUN wget -q https://raw.githubusercontent.com/yhirose/cpp-httplib/v0.15.3/httplib.h
RUN g++ -O2 -std=c++17 main.cpp -o app -lpthread
# 나쁜 점4: 런타임에 빌드 도구가 다 남음 → 이미지 비대
CMD ["/src/app"]
EXPOSE 8080
