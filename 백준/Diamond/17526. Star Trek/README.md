# [Diamond V] Star Trek - 17526 

[문제 링크](https://www.acmicpc.net/problem/17526) 

### 성능 요약

메모리: 8980 KB, 시간: 68 ms

### 분류

볼록 껍질을 이용한 최적화, 다이나믹 프로그래밍

### 문제 설명

<p>The United Federation of Planets (abbreviated as UFP) consisting of <em>n</em> planets is an interstellar union of planetary governments. All planets are numbered from 1 to <em>n</em>. The headquarters of UFP is located on the planet numbered 1. UFP has established a linear interstellar path that connects in sequence from planet 1 to planet <em>n</em>.</p>

<p>The spaceships developed for interstellar travel have almost unlimited energy, allowing the ship to move without stopping along the travel route between two planets. Each planet has its own spaceship model. The performance of the spaceships is almost same, but the speed varies by model. The spaceship’s pace is expressed as the number of hours required to move one light-year distance. The light-year is a distance unit used to express astronomical distances. If a ship’s pace is 10, then it takes 10 hours to travel one light-year.</p>

<p>You, a resident on planet 1, are about to travel to planet <em>n</em>. In order to arrive at planet <em>n</em> as quickly as possible, you can transfer to spaceships at other planets on the way. However, you have to know that such a transfer needs additional time to prepare for landing, takeoff, entry and departure formalities, etc.</p>

<p>For example, suppose that there are five planets in UFP, given with the distances between adjacent planets, the spaceship’s paces, and preparation times for the planets as in the figure below.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/56c71b07-85d3-474f-889d-a27e5e0e494d/-/preview/" style="width: 357px; height: 102px;"></p>

<p>If a spaceship on planet 1 moves directly to planet 5, it takes 165 (= 3 + 27 × 6) hours. If you transfer at planet 2, it takes 107 (= 3 + 5 × 6 + 8 + 22 × 3) hours. If you transfer at planet 2 and then at planet 4, it takes 130 (= 3 + 5 × 6 + 8 + 14 × 3 + 15 + 8 × 4) hours. Considering all the possible travel plans, the minimum time to get to planet 5 is 107 hours.</p>

<p>Given the information of planets and spaceships of UFP, write a program to find the minimum time to get from planet 1 to planet <em>n</em>.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing an integer, <em>n</em> (3 ≤ <em>n</em> ≤ 100,000), where <em>n</em> is the number of planets of UFP. The planets are numbered from 1 to <em>n</em>. The next line consists of <em>n</em> − 1 integers, where the <em>i</em>-th integer represents the distance between planet <em>i</em> and planet <em>i</em> + 1. All distances are between 1 and 1,000. In the following <em>n</em> − 1 lines, the <em>i</em>-th line contains two integers, <em>p</em> and <em>s</em> (0 ≤ <em>p</em> ≤ 10<sup>9</sup>, 1 ≤ <em>s</em> ≤ 10<sup>5</sup>), where <em>p</em> is the preparation time and <em>s</em> is the spaceship’s pace of planet <em>i</em>.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain an integer which represents the minimum time to travel from planet 1 to planet <em>n</em>.</p>

