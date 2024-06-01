#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include <memory>

template<typename type, int N, int M>
class MatrixBase
{
public:
    class Proxy
    {
        private:
        int row = 0;
        MatrixBase<type, N, M> &matrix;

        public :
            Proxy(int row, MatrixBase<type, N, M> &m) : matrix(m)
            {
                this->row = row;
            }

            type & operator[](int column)
            {
                return matrix.getAt(row, column);
            }
    };

    MatrixBase()
    {
        data = std::make_shared<type[][M]>(N);
    }

    type & getAt(int row, int column)
    {
        return data[row][column];
    }

    static std::shared_ptr<MatrixBase<type, N, M>> IdentityMatrix()
    {
        auto matrix = std::make_shared<MatrixBase<type, N, M>>();
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (i == j)
                {
                    matrix->getAt(i, j) = 1;
                }
                else
                {
                    matrix->getAt(i, j) = 0;
                }
            }
        }

        return matrix;
    }

    Proxy operator[](int row)
    {
        return Proxy(row, *this);
    }

protected:
    std::shared_ptr<type[][M]> data;
};

#endif // MATRIXBASE_H
