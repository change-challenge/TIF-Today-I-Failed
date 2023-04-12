/*
	문제 이름 : 피보나치2
	백준 주소 : https://www.acmicpc.net/problem/2748
	난이도 : 브론즈1
*/

import Foundation

var num = Int(readLine()!)!
var array : [Int] = []

for i in 0...num {
	if (i < 2) {
		array.append(i)
		continue;
	}
	array.append(array[i - 1] + array[i - 2])
}

print(array[num])
