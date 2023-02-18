
public abstract class Engine : Mechanism
{
    protected string? Name { get; set; }
    public override void SetInMotion() { Console.Write("Я кручу шестеренки\n"); }

    protected override string? FuelType { get; set; }
    public abstract bool IsWork { get; set; }

    protected abstract string? Operation();

}
public sealed class GasolineEngine : Engine
{
    new string? Name => String.Format("Я {0}", typeof(GasolineEngine).Name);
    public override void SetInMotion()
    {
        Console.Write($"{Name}, Я использую {FuelType}, {Operation}");
        base.SetInMotion();
    }

    protected override string? FuelType => "бензин";
    public override bool IsWork { get; set; } = false;

    protected override string? Operation() => "Я работаю тыр - тыр";
}
public sealed class DieselEngine : Engine
{
    new string? Name => String.Format("Я {0}", typeof(DieselEngine).Name);
    public override void SetInMotion()
    {
        Console.Write($"{Name}, Я использую {FuelType}, {Operation()}");
        base.SetInMotion();
    }

    protected override string? FuelType => "дизельное топливо";
    public override bool IsWork { get; set; } = false;

    protected override string? Operation() => "Я работаю мур - мур ";
}
public sealed class ElectricEngine : Engine
{
    new string? Name => String.Format("Я {0}", typeof(ElectricEngine).Name);
    public override void SetInMotion()
    {
        Console.Write($"{Name}, Я использую {FuelType}, {Operation}");
        base.SetInMotion();
    }

    protected override string? FuelType => "электричество";
    public override bool IsWork { get; set; } = false;

    protected override string? Operation() => "Я работаю бзз - бзз";
}
public sealed class JetEngine : Engine
{
    new string? Name => String.Format("Я {0}", typeof(JetEngine).Name);
    public override void SetInMotion()
    {
        Console.Write($"{Name}, Я использую {FuelType}, {Operation()}");
        Console.WriteLine("\nЯ отталкиваюсь от воздуха, выбрасывая струю раскаленного газа");
    }

    protected override string? FuelType => "реактивное топливо";
    public override bool IsWork { get; set; } = false;

    protected override string? Operation() => "Я работаю вжюх - вжюх";
}
