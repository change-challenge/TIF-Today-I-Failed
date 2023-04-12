/*
	문제 이름 : 계단 오르기
	백준 주소 : https://www.acmicpc.net/problem/2579
	난이도 : 실버3
*/

import Foundation

var num = Int(readLine()!)!
var array = Array(readLine()!).split(separator: " ").map {
	Int(String($0))!
}

print(array)
