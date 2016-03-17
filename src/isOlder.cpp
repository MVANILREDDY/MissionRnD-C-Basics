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
	int day, m, yr, x = 0;//x value is used to determine  given date is valid or not.if x=1,valid else not valid.
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

int isOlder(char *dob1, char *dob2) 
{
	if (valid(dob1) == 1 && valid(dob2) == 1)
	{
		int dob1_date, dob2_date;//converting given dates into integer formats based on date prototype.
		dob1_date = (10 * dob1[0] + dob1[1]) + (10 * dob1[3] + dob1[4]) * 31 + (1000 * dob1[6] + 100 * dob1[7] + 10 * dob1[8] + dob1[9]) * 12 * 31;
		dob2_date = (10 * dob2[0] + dob2[1]) + (10 * dob2[3] + dob2[4]) * 31 + (1000 * dob2[6] + 100 * dob2[7] + 10 * dob2[8] + dob2[9]) * 12 * 31;
		return (dob1_date < dob2_date) ? 1 : (dob1_date == dob2_date) ? 0 : 2;//using ternary operator for comparing dates.
	}
	else
		return -1;
}
