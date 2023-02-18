
public class Human : Organism
{
    protected string? Name => String.Format("Я {0}", typeof(Human).Name);
    protected override string? TypeOfFood => "приготовленную еду";
    public bool IsWork { get; set; }
    public override void SetInMotion()
    {
        Console.Write($"{Name}, Я использую {TypeOfFood}, {Operation}, Я шевелю телом");
    }
    protected virtual string? Operation() => "Я работаю фух - фух";

}

public sealed class RowingMan : Human
{
    string? Name => String.Format("Я {0}", typeof(RowingMan).Name);
    protected override string? TypeOfFood => "приготовленную еду";
    public bool IsWork { get; set; }    
    
    public new void SetInMotion()
    {
        Console.Write($"{Name}, Я использую {TypeOfFood}, {Operation}, Я гребу веслами");
    }
    protected override string? Operation() => "Я работаю уф - уф";
}

public class Horse : Organism
{
    string? Name => String.Format("Я {0}", typeof(Horse).Name);
    protected override string? TypeOfFood => "овёс";
    public bool IsWork { get; set; }
    public override void SetInMotion()
    {
        Console.Write($"{Name}, Я использую {TypeOfFood}, {Operation}, Я иду и тощу за собой");
    }
    string? Operation() => "Я работаю цок - цок";
}
