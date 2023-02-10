#define TASK_

using static System.Console;

//Реализовать алгорим быстрой сортировки на языке C#, и проверить его работу.
#if TASK_1

Random rnd = new Random();
int[] array = new int[rnd.Next(20,40)];

for (int i = 0; i < array.Length; i++) {
    array[i] = rnd.Next(0, 100);
    Write(array[i] + " ");
}

quicksort(array, 0, array.Length - 1);
WriteLine();

for (int i = 0; i < array.Length; i++) {
    Write(array[i] + " ");
}


void quicksort(int[] array, int bi, int ei) {
    if (bi < ei) {
        int q = partition(array, bi, ei);
        quicksort(array, bi, q);
        quicksort(array, q + 1, ei);
    }
}
int partition(int[] array, int bi, int ei) {
    int val = array[(bi + ei) / 2];    

    while (bi <= ei) {
        while (array[bi] < val) bi++;
        while (array[ei] > val) ei--;
        if (bi >= ei) break;
        swap(ref array[bi++],ref array[ei--]);
    }
    return ei;
}
void swap(ref int x,ref int y) {
    int temp = x; x = y;
    y = temp;
}

#endif //TASK_1

//Реализовать программу ход конем.
#if TASK_2

namespace task_101223 {

    class Program
    {
        const int SIZE = 8; 
        static Coordinate[] allowed_moves = new Coordinate[8];      
       
        static void Main(string[] args)
        {
            allowed_moves[0].X = -1; allowed_moves[0].Y = -2;
            allowed_moves[1].X = -2; allowed_moves[1].Y = -1;
            allowed_moves[2].X = -2; allowed_moves[2].Y = 1;
            allowed_moves[3].X = 1; allowed_moves[3].Y = -2;
            allowed_moves[4].X = -1; allowed_moves[4].Y = 2;
            allowed_moves[5].X = 2; allowed_moves[5].Y = -1;
            allowed_moves[6].X = 1; allowed_moves[6].Y = 2;
            allowed_moves[7].X = 2; allowed_moves[7].Y = 1;


            int[,] chessboard = new int[SIZE, SIZE];
            Coordinate begin_coordinates = new Coordinate(0, 0);
            int move = 1;
            int count = 1;
            chessPieceMovement(chessboard, begin_coordinates, move, ref count);
        }
        static void Print(int[,] chessboard)
        {
            for (int y = 0; y < chessboard.GetLength(0); y++, WriteLine())
            {
                for (int x = 0; x < chessboard.GetLength(1); x++)
                {
                    Write(chessboard[y, x] + "\t");
                }
                WriteLine();
            }
            WriteLine();
        }
        static void chessPieceMovement(int[,] chessboard, Coordinate coord, int move, ref int count)
        {
            chessboard[coord.Y, coord.X] = move;

            if (move == SIZE * SIZE) {
                WriteLine($"Count = {count++}");
                Print(chessboard);
                //chessboard[coord.Y, coord.X] = 0; // -если разкоментировать, будет выводить все возможные варианты поочереди
                return;
            }

            for (int variant = 0; variant < 8; variant++)
            {
                Coordinate new_coord = new Coordinate(coord.X + allowed_moves[variant].X, coord.Y + allowed_moves[variant].Y);

                if (moveIsPossible(new_coord) && chessboard[new_coord.Y, new_coord.X] == 0) {
                   
                    chessPieceMovement(chessboard, new_coord, move + 1,ref count);
                }
                
            }
            chessboard[coord.Y, coord.X] = 0;

        }
        static bool moveIsPossible(Coordinate coord)
        {
            return (coord.X >= 0 && coord.X < SIZE) && (coord.Y >= 0 && coord.Y < SIZE);
        }
        struct Coordinate
        {
            public Coordinate(int x, int y) { X = x; Y = y; }
            public int X { get; set; } = 0;
            public int Y { get; set; } = 0;
        }
    }
}

#endif //TASK_2