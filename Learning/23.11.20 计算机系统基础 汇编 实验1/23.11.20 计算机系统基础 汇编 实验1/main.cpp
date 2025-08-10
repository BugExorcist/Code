float_bits float_demorm_zero£¨float_bits f£©
{
unsigned sign = f >> 31;
unsigned exp = f >> 23 & 0xFF;
unsigned frac = f & 0x7FFFFF;
if £¨exp == 0£©
{
frac = 0
}
Return(sign << 31) | (exp << 23) | frac
}

int main()
{

	return 0;
}