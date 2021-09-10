void average(int length, int* numbers, float* result)
{
	int i, count, total;
	total = 0;
	count = 0;
	for (i = 0; i < length; i++)
	{
		if (numbers[i] <= 1) 
		{
			total = total + numbers[i];
			count = count + 1;
		}
	}
	if (count != 0) *result = total / count;

}