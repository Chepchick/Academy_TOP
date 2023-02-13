using task_11_02_23;

public class StateDerivative : StateBase
{
    StateDerivative state_derivative = new StateDerivative();

    public void SomeMethodStateDerivative()
    {
        //В той же сборке (build_#1) из класса наследника при открытом наследовании базового класса
        //доступ имеется ко всем полям и методам базового класса, кроме private - объявлленных в базовом классе.

        Console.WriteLine(state_derivative.default_var);//Ошибка 
        Console.WriteLine(state_derivative.private_var);//Ошибка 
        Console.WriteLine(state_derivative.protected_private_var);
        Console.WriteLine(state_derivative.protected_var);
        Console.WriteLine(state_derivative.internal_var);
        Console.WriteLine(state_derivative.protected_internal_var);
        Console.WriteLine(state_derivative.public_var);

        state_derivative.Print();//Ошибка 
        state_derivative.PrintPrivate();//Ошибка 
        state_derivative.PrintProtectedPrivate();
        state_derivative.PrintProtected();
        state_derivative.PrintInternal();
        state_derivative.PrintProtectedInternal();
        state_derivative.PrintPublic();
    }
}


