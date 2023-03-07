# ENG_EC_330_Algorithms

## PA_1
a) Write a program to generate the result of fun(x, y) for non-negative integer inputs x and y. The function fun(x, y) is defined as follows.
𝑓𝑢𝑛(𝑥, 𝑦) =
      1                               IF 𝑥 = 0 𝑎𝑛𝑑 𝑦 = 0
      𝑓𝑢𝑛(1, 𝑦 − 1)                   IF 𝑥 = 0 𝑎𝑛𝑑 𝑦 ≠ 0
        𝑥 + 1                         IF 𝑥 ≠ 0 𝑎𝑛𝑑 𝑦 = 0
      𝑓𝑢𝑛(𝑥 − 1, 𝑓𝑢𝑛(𝑥 − 1, 𝑦 − 1))   IF 𝑜𝑡ℎ𝑒𝑟𝑤𝑖𝑠𝑒

b) Wenchao wants to divide the class into two (non-empty) project groups based on the students' birthdays. In particular, we are going to consider only the day of birth (i.e. an integer between 1 and 31) and not the month or the year. We want the two
groups to be "balanced" in such a way that the difference between the sum of birthdays of one group and the sum of birthdays of the other group is minimized.
For example, say the birthdays for students Alice, Bob, Charlie, Drew and Edward are 3, 27, 4, 5 and 20 respectively. The most balanced group assignment would be {Alice, Bob} and {Charlie, Drew, Edward} since | (3 + 27) - (4 + 5 + 20) | = 1 (| |
indicates taking the absolute value) is the smallest among all possible assignments. Develop an algorithm to help Wenchao determine the most balanced group
assignment for the class.
