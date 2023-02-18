
public sealed class SchoolBas: Bas
{
    public SchoolBas()
    {
        Name = String.Format("Я {0}", typeof(SchoolBas).Name);
        CargoType = "школьников";
        LoadCapacity = 30;
        Mover = new DieselEngine();
    }
    new string? Name { get; set; }
    new string? CargoType { get; set; }
    new int? LoadCapacity { get; set; }
    new public IMover? Mover { get; set; }

    public override void Moving()
    {        
        if (Mover.IsWork)
        {           
            Mover.SetInMotion();
            Console.WriteLine($"{Name}, Я могу возить {Undercarriage} {LoadCapacity} {CargoType} ");
        }
        else
        {
            Console.WriteLine("Двигатель не запущен, автобус не поедет");
        }
    }
}

public sealed class PassengerPlane: HeavierThanAirVehicles
{
    public PassengerPlane()
    {
        Name = String.Format("Я {0}", typeof(PassengerPlane).Name);        
        LoadCapacity = 120;
        Mover = new JetEngine();
    }
    new string? Name { get; set; }    
    new int? LoadCapacity { get; set; }
    new public IMover? Mover { get; set; }

    public override void Moving()
    {
        if (Mover.IsWork)
        {
            Mover.SetInMotion();
            Console.WriteLine($"{Name}, Я {FlyingAltitude} в воздухе переношу на себе {LoadCapacity} {CargoType} ");
        }
        else
        {
            Console.WriteLine("Двигатели не запущены, самолет не полетит");
        }
    }
}


class Program
{
    static void Main()
    {
        SchoolBas? schoolBas = new SchoolBas();
        
        schoolBas.Moving();
        Console.WriteLine();
        schoolBas.Mover.IsWork = true;
        schoolBas.Moving();
        Console.WriteLine();
        Console.WriteLine();

        PassengerPlane passengerPlane = new PassengerPlane();

        
        passengerPlane.Moving();
        Console.WriteLine();
        passengerPlane.Mover.IsWork = true;
        passengerPlane.Moving();

    }
}