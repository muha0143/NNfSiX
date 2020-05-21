
/**
 * Creates a dense layer 
 * 
 * Associated tutorial https://www.youtube.com/watch?v=TEWy9vZcxW4
 */

#include <vector>
#include <numeric>
#include <iostream>

typedef std::vector< std::vector< double> >     dmatrix; // dmatrix stands for dynamic matrix
typedef std::vector< double >                   drow;    // drow stands for dynamic row

// matrix transpose function
dmatrix T(const dmatrix& m){
    dmatrix mat;
    for(size_t i=0; i<m[0].size(); i++){
        mat.push_back({});
        for(size_t j=0; j<m.size(); j++){
            mat[i].push_back(m[j][i]);
        }
    }return mat;
}

// matrix multiplication operator
dmatrix operator*(const dmatrix& m1, const dmatrix& m2){
    auto m3 = T(m2);
    dmatrix rval;
    for(size_t i=0; i<m1.size(); i++){
        rval.push_back({});
        for(size_t j=0; j<m3.size(); j++){
            rval[i].push_back(std::inner_product(m1[i].begin(), m1[i].end(), m3[j].begin(), 0.0));
        }
    }return rval;
}

// matrix vector addition operator
dmatrix operator+(const dmatrix& m, const drow& row){
    dmatrix     xm;
    for(size_t j=0; j<m.size(); j++){
        xm.push_back({});
        for(size_t i=0; i< m[j].size(); i++){
            xm[j].push_back( m[j][i] + row[j]);
        }
    }return xm;
}

// ostream << operator for matrix
std::ostream& operator<<(std::ostream& os,const dmatrix& dm){
    for(auto& row : dm){
        for(auto& item : row)
            os << item << " ";
        os << "\n";
    }return os;
}

// Dense Layer class 
class dense_layer {
    private:
        dmatrix     m_weights, m_output;
        drow        m_biases;

    public:
        // constructor 
        dense_layer( const size_t& n_input, const size_t& n_neuron) : m_weights(n_input, drow(n_neuron)){
            for(size_t j=0; j<n_neuron; j++){
                for(size_t i=0; i<n_input; i++)
                    m_weights[i][j] = ( 2*(0.5 - double(rand())/double(RAND_MAX)) );
                m_biases.push_back(0);//2*(0.5 - double(rand())/double(RAND_MAX)));
            }
        }
        // forward pass
        void forward( const dmatrix& inputs){
            m_output = inputs * m_weights + m_biases;
        }

        dmatrix output() const {
            return m_output;
        }
};

int main(){
    dense_layer l1(4, 5);
    dense_layer l2(5, 2);

    dmatrix a{
        drow{1,2,3,2.5},
        drow{2,5,-1, 2},
        drow{-1.5, 2.7, 3.3, -0.8}
    };

    l1.forward(a);
    std::cout << " First Layer forward pass output : \n"<< l1.output() << "\n";
    l2.forward(l1.output());
    std::cout << " Second Layer forward pass output : \n" << l2.output() << "\n";

    return 0;
}
