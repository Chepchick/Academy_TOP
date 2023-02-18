
public interface IMover
{
    protected abstract string? Name { get;set;}
    public abstract bool IsWork { get; set; }
    public abstract void SetInMotion();
}

public abstract class Mechanism : IMover
{
    string? IMover.Name { get; set; }
    bool IMover.IsWork { get; set; }
    public abstract void SetInMotion();

    protected virtual string? FuelType { get; set; }
}

public abstract class Organism : IMover
{
    string? IMover.Name { get; set; }
    protected virtual string? TypeOfFood { get; set; }
    bool IMover.IsWork { get; set; }

    public abstract void SetInMotion();
}

public abstract class Natural : IMover
{
    bool IMover.IsWork { get; set; }
    protected virtual string? TypeOfElement { get; set; }
    string? IMover.Name { get; set; }

    public abstract void SetInMotion();
}