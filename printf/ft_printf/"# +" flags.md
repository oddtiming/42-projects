- "# +" flags:
	- "#" :	"For x and X conversions, a non-zero result has the string '0x' (or '0X' for X conversions) prepended to it.
			For a, A, e, E, f, F, g, and G conversions, the result will always contain a decimal
			point, even if no digits follow it (normally, a decimal point appears in the results of those conversions
			only if a digit follows).  For g and G conversions, trailing zeros are not removed from the result as
			they would otherwise be." - man 3 printf
	- " " :	"A blank should be left before a positive number produced by a signed conversion (a, A, d, e, E, f, F, g, G, or i)." - man 3 printf
	- "+" :	"A sign must always be placed before a number produced by a signed conversion.
			A "+" overrides a space if both are used." - man 3 printf