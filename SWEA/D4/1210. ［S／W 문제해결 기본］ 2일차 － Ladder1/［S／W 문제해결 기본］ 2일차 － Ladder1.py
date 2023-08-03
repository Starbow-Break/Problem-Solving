# 이동방향
UP = 0
LEFT = 1
RIGHT = 2

dr = [-1, 0, 0]
dc = [0, -1, 1]

for t in range(1, 11):
    tc = int(input()) # 테스트 케이스 번호
    ladder = [] # 사다리 게임판

    # 사다리 게임판 받기
    for i in range(100):
        ladder.append(list(map(int, input().split())))

    cur = [-1, -1] # 현재 위치
    direction = UP # 이동 방향
    # 2가 적혀있는 칸에서 시작
    # 시작 위치 찾기
    for i in range(100):
        if ladder[99][i] == 2:
            cur = [99, i]
            break

    # 맨 위에 도달할 때 까지
    while cur[0] > 0:
        # 이동 전 방향 전환
        if direction == UP:
            # 왼쪽에 사다리가 있으면 방향 전환
            if cur[1] > 0 and ladder[cur[0]][cur[1]-1] == 1:
                direction = LEFT
            # 오른쪽에 사다리가 있으면 방향 전환
            elif cur[1] < 99 and ladder[cur[0]][cur[1]+1] == 1:
                direction = RIGHT
        elif direction == LEFT:
            # 왼쪽으로 더 이상 이동이 불가능하면 방향 전환
            if cur[1] == 0 or ladder[cur[0]][cur[1]-1] == 0:
                direction = UP
        else:
            # 오른쪽으로 더 이상 이동이 불가능하면 방향 전환
            if cur[1] == 99 or ladder[cur[0]][cur[1] + 1] == 0:
                direction = UP

        # 이동
        cur[0] += dr[direction]
        cur[1] += dc[direction]

    print(f'#{tc} {cur[1]}')