# [Platinum III] Starting a Scenic Railroad Service - 15337 

[문제 링크](https://www.acmicpc.net/problem/15337) 

### 성능 요약

메모리: 12808 KB, 시간: 84 ms

### 분류

자료 구조, 그리디 알고리즘, 세그먼트 트리, 스위핑

### 제출 일자

2023년 11월 30일 22:30:56

### 문제 설명

<p>Jim, working for a railroad company, is responsible for planning a new tourist train service. He is sure that the train route along a scenic valley will arise a big boom, but not quite sure how big the boom will be.</p>

<p>A market survey was ordered and Jim has just received an estimated list of passengers’ travel sections. Based on the list, he’d like to estimate the minimum number of train seats that meets the demand.</p>

<p>Providing as many seats as all of the passengers may cost unreasonably high. Assigning the same seat to more than one passenger without overlapping travel sections may lead to a great cost cutback.</p>

<p>Two different policies are considered on seat assignments. As the views from the train windows depend on the seat positions, it would be better if passengers can choose a seat. One possible policy (named ‘policy-1’) is to allow the passengers to choose an arbitrary seat among all the remaining seats when they make their reservations. As the order of reservations is unknown, all the possible orders must be considered on counting the required number of seats.</p>

<p>The other policy (named ‘policy-2’) does not allow the passengers to choose their seats; the seat assignments are decided by the railroad operator, not by the passengers, after all the reservations are completed. This policy may reduce the number of the required seats considerably.</p>

<p>Your task is to let Jim know how different these two policies are by providing him a program that computes the numbers of seats required under the two seat reservation policies.</p>

<p>Let us consider a case where there are four stations, S1, S2, S3, and S4, and four expected passengers p1, p2, p3, and p4 with the travel list below.</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15337/1.png" style="height:107px; width:269px"></p>

<p>The travel sections of p1 and p2 do not overlap, that of p3 overlaps those of p1 and p2, and that of p4 does not overlap those of any others.</p>

<p>Let’s check if two seats would suffice under the policy-1. If p1 books a seat first, either of the two seats can be chosen. If p2 books second, as the travel section does not overlap that of p1, the same seat can be booked, but the other seat may look more attractive to p2. If p2 reserves a seat different from that of p1, there will remain no available seats for p3 between S1 and S3 (Figure I.1).</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15337/2.png" style="height:120px; width:416px"></p>

<p style="text-align:center">Figure I.1. With two seats</p>

<p>With three seats, p3 can find a seat with any seat reservation combinations by p1 and p2. p4 can also book a seat for there are no other passengers between S3 and S4 (Figure I.2).</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15337/3.png" style="height:120px; width:415px"></p>

<p style="text-align:center">Figure I.2. With three seats</p>

<p>For this travel list, only three seats suffice considering all the possible reservation orders and seat preferences under the policy-1.</p>

<p>On the other hand, deciding the seat assignments after all the reservations are completed enables a tight assignment with only two seats under the policy-2 (Figure I.3).</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15337/4.png" style="height:92px; width:417px"></p>

<p style="text-align:center">Figure I.3. Tight assignment to two seats</p>

### 입력 

 <p>The input consists of a single test case of the following format.</p>

<pre>n
a<sub>1</sub> b<sub>1</sub>
.
.
.
a<sub>n</sub> b<sub>n</sub></pre>

<p>Here, the first line has an integer n, the number of the passengers in the estimated list of passengers’ travel sections (1 ≤ n ≤ 200 000). The stations are numbered starting from 1 in their order along the route. Each of the following n lines describes the travel for each passenger by two integers, the boarding and the alighting station numbers, a<sub>i</sub> and b<sub>i</sub>, respectively (1 ≤ a<sub>i</sub> < b<sub>i</sub> ≤ 100 000). Note that more than one passenger in the list may have the same boarding and alighting stations.</p>

### 출력 

 <p>Two integers s1 and s2 should be output in a line in this order, separated by a space. s1 and s2 are the numbers of seats required under the policy-1 and -2, respectively.</p>

