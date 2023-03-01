using Fracion;

Fraction A = 1.2;
Fraction B = 1.0;
Fraction C = new(2, 7);
Fraction D = new(1, 3, 8);

Console.WriteLine($"B + C = {1 + C}");
Console.WriteLine($"A - D = {A - D}");
Console.WriteLine($"D * A = {D * A}");
Console.WriteLine($"C / A = {C / A}");

Console.WriteLine();
Console.WriteLine($"A == B {A == B}");
Console.WriteLine($"D != C {D != C}");
Console.WriteLine($"C > B {C > B}");
Console.WriteLine($"B < A {B < A}");
Console.WriteLine($"D >= C {D >= C}");
Console.WriteLine($"C <= A {C <= A}");



