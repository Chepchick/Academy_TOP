using task_11_02_23;

namespace build__2
    
{
    public class StateDerrivative_2: StateBase
    {
        StateDerrivative_2 state_derrivative_2 = new StateDerrivative_2();

        public void SomeMethodStateDerivative_2()
        {
            //В другой сборке (build_#2) из класса наследника при открытом наследовании базового класса
            //доступ имеется к public, protected internal, protected.

            Console.WriteLine(state_derrivative_2.default_var);//Ошибка 
            Console.WriteLine(state_derrivative_2.private_var);//Ошибка 
            Console.WriteLine(state_derrivative_2.protected_private_var);//Ошибка
            Console.WriteLine(state_derrivative_2.protected_var);
            Console.WriteLine(state_derrivative_2.internal_var);//Ошибка
            Console.WriteLine(state_derrivative_2.protected_internal_var);
            Console.WriteLine(state_derrivative_2.public_var);

            state_derrivative_2.Print();//Ошибка 
            state_derrivative_2.PrintPrivate();//Ошибка 
            state_derrivative_2.PrintProtectedPrivate();//Ошибка
            state_derrivative_2.PrintProtected();
            state_derrivative_2.PrintInternal();//Ошибка
            state_derrivative_2.PrintProtectedInternal();
            state_derrivative_2.PrintPublic();
        }
    }
}
