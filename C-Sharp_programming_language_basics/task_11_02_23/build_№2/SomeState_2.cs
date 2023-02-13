using task_11_02_23;

internal class SomeState_2
{
    SomeState_2 someState_2 = new SomeState_2();

    public void SomeMethodSomeState_2(StateBase stateBase)
    {
        //В сборке (build_#2) из класса, не являющемся наследником базового класса
        //доступ имеется только к полям и методам с модификатором public,
        //то есть закрыт доступ для всех остальных модификаторов

        Console.WriteLine(stateBase.default_var);//Ошибка 
        Console.WriteLine(stateBase.private_var);//Ошибка 
        Console.WriteLine(stateBase.protected_private_var);//Ошибка
        Console.WriteLine(stateBase.protected_var);//Ошибка
        Console.WriteLine(stateBase.internal_var);//Ошибка 
        Console.WriteLine(stateBase.protected_internal_var);//Ошибка 
        Console.WriteLine(stateBase.public_var);

        stateBase.Print();//Ошибка 
        stateBase.PrintPrivate();//Ошибка 
        stateBase.PrintProtectedPrivate();//Ошибка
        stateBase.PrintProtected();//Ошибка
        stateBase.PrintInternal();//Ошибка 
        stateBase.PrintProtectedInternal();//Ошибка 
        stateBase.PrintPublic();
    }
}
