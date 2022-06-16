//C實現先乘除後加減有括號先算的計算

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#define lli long long int
char s1[1000005], s2[3000005],s3[1000005];
lli k1[1000005] = { 0 };
int main()
{
	int p = 0;
	int n = 0;
	scanf("%s",s3);
	int ss1 = 0, ss2 = 0,num=0;
	for (int i = 0; i < strlen(s3); i++) {
		if ('0' <= s3[i] && s3[i] <= '9') {
			while ('0' <= s3[i] && s3[i] <= '9') {
				s2[ss2++] = s3[i];
				i++;
			}
			s2[ss2++] = ',';
			i--;
		}
		else if(s3[i]=='=') {
			
			for (int j = ss1 - 1; j >= 0; j--) s2[ss2++] = s1[j];
			for (int j = 0; j < strlen(s2); j++) {
				if (s2[j] == ',')continue;
				else if ('0' <= s2[j] && s2[j] <= '9') {
					bool chk = false;

					if (s2[j - 1] == '-')chk = true;
					k1[n] = k1[n] * 10 + (int)(s2[j] - '0');

					while ('0' <= s2[j + 1] && s2[j + 1] <= '9') {
						j++;
						k1[n] = k1[n] * 10 + (int)(s2[j] - '0');

					}
					if (chk)k1[n] *= -1;
					n++;
				}
				else if (s2[j] == '+') {
					lli p1 = k1[--n];
					lli p2 = k1[--n];
					k1[n] = p1 + p2;
					n++;
					k1[n] = 0;
				}
				else if (s2[j] == '-') {
					if (s2[j + 1] == ',' || s2[j + 1] == '\0') {
						lli p1 = k1[--n];
						lli p2 = k1[--n];
						k1[n] = p2 - p1;
						n++;
						k1[n] = 0;
					}

				}
				else if (s2[j] == '*') {
					lli p1 = k1[--n];
					lli p2 = k1[--n];
					k1[n] = p1 * p2;

					n++;
					k1[n] = 0;
				}
				else if (s2[j] == '/') {
					lli p1 = k1[--n];
					lli p2 = k1[--n];
					lli a1;
					if (p1 < 0 && p2 < 0) {
						a1 = abs(p2) / abs(p1);

					}
					else if (p1 < 0 && p2>0) {
						a1 = (abs(p2) / abs(p1)) * -1;
					}
					else if (p1 >= 0 && p2 < 0) {
						a1 = (abs(p2) / abs(p1) + 1) * -1;
					}
					else
					{
						a1 = p2 / p1;
					}

					k1[n] = a1;
					n++;
					k1[n] = 0;
				}
				else if (s2[j] == '^')k1[n-1] *= -1;
				else if (s2[j] == '%') {
					lli p1 = k1[--n];
					lli p2 = k1[--n];
					lli a1 = p2 % p1;
					k1[n] = a1;
					n++;
					k1[n] = 0;
				}
			}
			printf("Print: %lld\n", k1[0]);
			int str2_len = strlen(s2);
			memset(s2, '\0', str2_len);
			int str1_len = strlen(s1);
			memset(s1, '\0', str1_len);
			int k2 = k1[0];
			int len = 0;
			
			
			ss1 = 0;
			ss2 = 0;
			n = 1;
		}
		else if (s3[i] == '(') {
			s1[ss1++] = '(';
			
		}
		else if (s3[i] == ')') {
			while (s1[ss1-1] != '(') {
				s2[ss2++] = s1[ss1-1];
				s2[ss2++] = ',';
				s1[ss1-1] = '\0';
				ss1--;
			}
			s1[--ss1] = '\0';
		}
		else if (s3[i] == '+' || s3[i] == '-') {
				if (ss1 - 1 < 0) {
					s1[0] = s3[i];
					ss1++;
				}
				else {
					
					while (!(s1[ss1 - 1] == '(' || s1[ss1 - 1] == ')' )||( s1[ss1 - 1] == '+' || s1[ss1 - 1] == '-')) {
						
						s2[ss2++] = s1[ss1 - 1];
						s2[ss2++] = ',';

						ss1--;
						if (ss1 - 1 < 0) {
							break;
						}
					}
					if (s3[i - 1] == '('&&s3[i]=='-')s1[ss1++] = '^';
					else s1[ss1++] = s3[i];
				}
		}
		else if (s3[i] == '*' || s3[i] == '/'||s3[i]=='%') {
			if (ss1 - 1 < 0) {
				s1[0] = s3[i];
				ss1++;
			}
			else {
				while ((s1[ss1 - 1] == '*' || s1[ss1 - 1] == '/'||s1[ss1-1]=='%')) {
					s2[ss2++] = s1[ss1 - 1];
					s2[ss2++] = ',';

					s1[ss1--]='\0';
					if (ss1 - 1 < 0) break;
				}
				s1[ss1++] = s3[i];
			}
		}
	}
	system("pause");
}

