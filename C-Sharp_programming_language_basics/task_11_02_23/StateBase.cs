namespace task_11_02_23
{
   public class StateBase
    {
        //внутри класса доступ ко всем полям и метолам

        string default_var = "default";
        private string private_var = "private";

        protected private string protected_private_var = "protected private";
        protected string protected_var = "protected";
        internal string internal_var = "internal";

        protected internal string protected_internal_var = "protected internal";
        public string public_var = "public";

        void Print() => Console.WriteLine(default_var);

        private void PrintPrivate() => Console.WriteLine(private_var);

        protected private void PrintProtectedPrivate() => Console.WriteLine(protected_private_var);

        protected void PrintProtected() => Console.WriteLine(protected_var);

        internal void PrintInternal() => Console.WriteLine(internal_var);

        protected internal void PrintProtectedInternal() => Console.WriteLine(protected_internal_var);

        public void PrintPublic() => Console.WriteLine(public_var);
    }
}
