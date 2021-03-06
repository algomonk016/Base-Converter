# Base-Converter
This application converts a number of base m to a number of base n (m and n are any valid bases ). <br>
It is developed using C++. <br>
<br>
### Input format: <br>
Here is the input format for this application :
- base from which you want to convert
- if base is greater than 10, <br>
   - provide characters with their values
- number which is to be converted
- base in which you want to convert
- if base is greater than 10, <br>
   - provide characters with their values
<br><br>

![base](https://user-images.githubusercontent.com/55861951/102896141-e8b12b00-448b-11eb-8575-079000246611.PNG)

## Functions Used : <br>
1. ***string numToDecimal(string num, int base)*** : <br>
		- this function converts the provided number into decimal number. <br>
		- it takes two arguments, first is the number as a string and the oter is base to be converted as an integer. <br>
		- after conversion, returns the decimal number as a string. <br> <br>

2. ***string numToBase(string num, int base)*** : <br>
		- this function converts the provided decimal number into a number of any base. <br>
		- it takes two arguments, first is the decimal number as a string and other is base in which we have to convert (as an integer). <br>
		- after conversion, returns the final number as a string. <br> <br>

SAMPLE-INPUT
---
6 <br>
345.34 <br>
16 <br>
A 10 <br>
B 11 <br>
C 12 <br>
D 13 <br>
E 14 <br>
F 15 <br>


SAMPLE-OUTPUT
---
Converting number in base 10: <br>
(5* 6^0) + (4* 6^1) + (3* 6^2) + (3* 6^-1) + (4* 6^-2) <br>
Number in base 10: 137.611111 <br>
<br>
Converting from base 10 to base 16:  <br>

Integer part of base 10 Number: <br>
137/16,  Remainder: 9 <br>
8/16,  Remainder: 8 <br>
 
Fractional Part of base 10 number: <br>
9.77778 * 16 ==> 9 <br>
12.4444 * 16 ==> 12 <br>
7.11066 * 16 ==> 7 <br>
1.7705 * 16 ==> 1 <br>
12.3279 * 16 ==> 12 <br>
5.24698 * 16 ==> 5 <br>
3.95162 * 16 ==> 3 <br>
 
Number in base 16: 89.9C71C53 <br>
