using task_11_02_23;

public class SomeState
{
    SomeState someState = new SomeState();

    public void SomeMethodSomeState(StateBase stateBase)
    {
        //В той же сборке (build_#1) из класса, не являющемся наследником базового класса
        //доступ имеется к полям и методам с тремя модификаторами доступа: internal, protected internal и public.
        //то есть закрыт доступ для модификаторов private и protected

        Console.WriteLine(stateBase.default_var);//Ошибка 
        Console.WriteLine(stateBase.private_var);//Ошибка 
        Console.WriteLine(stateBase.protected_private_var);//Ошибка
        Console.WriteLine(stateBase.protected_var);//Ошибка
        Console.WriteLine(stateBase.internal_var);
        Console.WriteLine(stateBase.protected_internal_var);
        Console.WriteLine(stateBase.public_var);

        stateBase.Print();//Ошибка 
        stateBase.PrintPrivate();//Ошибка 
        stateBase.PrintProtectedPrivate();//Ошибка
        stateBase.PrintProtected();//Ошибка
        stateBase.PrintInternal();
        stateBase.PrintProtectedInternal();
        stateBase.PrintPublic();
    }
}