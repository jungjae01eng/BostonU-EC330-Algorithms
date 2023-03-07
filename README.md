# ENG_EC_330_Algorithms

## PA_1
1) Write a program to generate the result of fun(x, y) for non-negative integer inputs x and y. The function fun(x, y) is defined as follows.
𝑓𝑢𝑛(𝑥, 𝑦) =
      1 IF 𝑥 = 0 𝑎𝑛𝑑 𝑦 = 0 | 𝑓𝑢𝑛(1, 𝑦 − 1) IF 𝑥 = 0 𝑎𝑛𝑑 𝑦 ≠ 0 | 𝑥 + 1 IF 𝑥 ≠ 0 𝑎𝑛𝑑 𝑦 = 0 | 𝑓𝑢𝑛(𝑥 − 1, 𝑓𝑢𝑛(𝑥 − 1, 𝑦 − 1)) IF 𝑜𝑡ℎ𝑒𝑟𝑤𝑖𝑠𝑒

2) Wenchao wants to divide the class into two (non-empty) project groups based on the students' birthdays. In particular, we are going to consider only the day of birth (i.e. an integer between 1 and 31) and not the month or the year. We want the two
groups to be "balanced" in such a way that the difference between the sum of birthdays of one group and the sum of birthdays of the other group is minimized.
For example, say the birthdays for students Alice, Bob, Charlie, Drew and Edward are 3, 27, 4, 5 and 20 respectively. The most balanced group assignment would be {Alice, Bob} and {Charlie, Drew, Edward} since | (3 + 27) - (4 + 5 + 20) | = 1 (| |
indicates taking the absolute value) is the smallest among all possible assignments. Develop an algorithm to help Wenchao determine the most balanced group
assignment for the class.

## PA_2
1)  Consider only the numerical part of your BU ID and treat that as an integer. Wenchao wants to find the two students in the class such that the sum of their BU IDs modulo 330 is the smallest. You can assume that 𝑥 𝑚𝑜𝑑 330 is in the range of [0, 329] for any integer 𝑥. Your code must run asymptotically faster than 𝑶(𝑛^2) where 𝑛 is the number of students in the class

2) Consider again the numerical part of your BU ID and treat that as an integer. We can arrange all the permutations of the BU IDs in the class lexicographically. For instance, for Alice, Bob and Carol’s BU IDs (7305, 2204 and 1573), the lexicographical order is [1573, 2204, 7305], [1573, 7305, 2204], [2204, 1573, 7305], …. Given a permutation of the students’ BU IDs, Wenchao wants to the find the permutation that is right before it in the lexicographical order of the permutations. Your algorithm must run asymptotically faster than the brute-force approach that takes 𝑶(𝑛!) time to enumerate all the permutations. You are not allowed to use any existing
library function that directly solves this problem (e.g., prev_permutation from <algorithm>)
