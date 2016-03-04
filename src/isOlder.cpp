/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int valid(char*);
int valid(char *a)
{
	int day, m, yr, x = 0;
	day = 10 * (a[0] - '0') + a[1] - '0';
	m = 10 * (a[3] - '0') + a[4] - '0';
	yr = 1000 * (a[6] - '0') + 100 * (a[7] - '0') + 10 * (a[8] - '0') + (a[9] - '0');
	if (yr != 0)
	{
		if (m < 13 && m>0)
		{
			if (m == 4 || m == 6 || m == 9 || m == 11)
			{
				if (day < 31 && day>0){ x = 1; }
			}
			else if (m == 2)
			{
				if ((yr % 4 == 0) && (yr % 100 != 0) || yr % 400 == 0)
				{
					if (day < 30 && day>0){ x = 1; }
				}
				else
				{
					if (day < 29 && day>0){ x = 1; }
				}
			}
			else
			{
				if (day < 32 && day>0){ x = 1; }
			}
			return x;
		}
	}
	else
	{
		return 0;
	}
}

int isOlder(char *dob1, char *dob2) {
	if (valid(dob1) == 1 && valid(dob2) == 1)
	{
		int  yr1, yr2, order = 0;
		yr1 = 1000 * (dob1[6] - '0') + 100 * (dob1[7] - '0') + 10 * (dob1[8] - '0') + (dob1[9] - '0');
		yr2 = 1000 * (dob2[6] - '0') + 100 * (dob2[7] - '0') + 10 * (dob2[8] - '0') + (dob2[9] - '0');
		if (yr1 > yr2)
		{
			order = 2;
		}
		else if (yr1 < yr2)
		{
			order = 1;
		}
		else
		{
			yr1 = 10 * (dob1[3] - '0') + dob1[4] - '0';
			yr2 = 10 * (dob2[3] - '0') + dob2[4] - '0';
			if (yr1>yr2)
			{
				order = 2;
			}
			else if (yr1<yr2)
			{
				order = 1;
			}
			else
			{
				yr1 = 10 * (dob1[0] - '0') + dob1[1] - '0';
				yr2 = 10 * (dob2[0] - '0') + dob2[1] - '0';

				if (yr1>yr2)
				{
					order = 2;
				}
				else if (yr1<yr2)
				{
					order = 1;
				}
				else
				{
				}
			}
		}
		return order;
	}
	else
	{
		return -1;
	}
}

