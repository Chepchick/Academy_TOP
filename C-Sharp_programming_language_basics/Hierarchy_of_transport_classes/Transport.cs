
public abstract class Transport
{
    protected string? Name { get; set; }
    protected string? CargoType { get; set; }
    protected int? LoadCapacity { get; set; }
    public IMover? Mover { get; set; }

    public abstract void Moving();
}


public abstract class GroundTransport : Transport
{
    protected string? Undercarriage { get; set; }
}
public abstract class WaterTransport : Transport
{
    protected uint? Displacement { get; set; }
}
public abstract class AirTransport : Transport
{
    protected uint? FlyingAltitude { get; set; }
}


public abstract class AutoTransport : GroundTransport { }
public abstract class RailTransport : GroundTransport { }
public abstract class HorseDrawnTransport : GroundTransport { }


public abstract class SelfPropelledShip : WaterTransport { }
public abstract class NonSelfPropelledVessel : WaterTransport { }



public abstract class LighterThanAirVehicles : AirTransport { }
public abstract class HeavierThanAirVehicles : AirTransport {

    new protected string? CargoType => "человек";

    new protected string? FlyingAltitude => "высоко";
}


public abstract class Bas : AutoTransport {
    new protected string? CargoType => "людей";

    new protected string? Undercarriage => "на резиновых колесах";
}