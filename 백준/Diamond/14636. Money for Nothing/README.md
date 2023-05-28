# [Diamond IV] Money for Nothing - 14636 

[문제 링크](https://www.acmicpc.net/problem/14636) 

### 성능 요약

메모리: 28500 KB, 시간: 400 ms

### 분류

분할 정복, 분할 정복을 사용한 최적화, 다이나믹 프로그래밍, 기하학

### 문제 설명

<p>In this problem you will be solving one of the most profound challenges of humans across the world since the beginning of time – how to make lots of money.</p>

<p>You are a middleman in the widget market. Your job is to buy widgets from widget producer companies and sell them to widget consumer companies. Each widget consumer company has an open request for one widget per day, until some end date, and a price at which it is willing to buy the widgets. On the other hand, each widget producer company has a start date at which it can start delivering widgets and a price at which it will deliver each widget.</p>

<p>Due to fair competition laws, you can sign a contract with only one producer company and only one consumer company. You will buy widgets from the producer company, one per day, starting on the day it can start delivering, and ending on the date specified by the consumer company. On each of those days you earn the difference between the producer’s selling price and the consumer’s buying price.</p>

<p>Your goal is to choose the consumer company and the producer company that will maximize your profits.</p>

### 입력 

 <p>The first line of input contains two integers m and n (1 ≤ m, n ≤ 500 000) denoting the number of producer and consumer companies in the market, respectively. It is followed by m lines, the i th of which contains two integers p<sub>i</sub> and d<sub>i</sub> (1 ≤ p<sub>i</sub>, d<sub>i</sub> ≤ 10<sup>9</sup>), the price (in dollars) at which the i th producer sells one widget and the day on which the first widget will be available from this company. Then follow n lines, the j th of which contains two integers q<sub>j</sub> and e<sub>j</sub> (1 ≤ q<sub>j</sub>, e<sub>j</sub> ≤ 10<sup>9</sup>), the price (in dollars) at which the j th consumer is willing to buy widgets and the day immediately after the day on which the last widget has to be delivered to this company.</p>

### 출력 

 <p>Display the maximum total number of dollars you can earn. If there is no way to sign contracts that gives you any profit, display 0.</p>

