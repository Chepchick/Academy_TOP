public sealed class Wind : Natural
{
    string? Name => String.Format("Я {0}", typeof(Wind).Name);
    protected override string? TypeOfElement => "воздух";
    public bool IsWork { get; set; }

    public override void SetInMotion()
    {
        Console.Write($"{Name}, Я использую {TypeOfElement}, {Operation}, Я толкаю");
    }
    string? Operation() => "Я дую фууу - фууу";
}