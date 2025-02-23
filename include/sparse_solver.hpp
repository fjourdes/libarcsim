/*
Copyright �2013 The Regents of the University of California
(Regents). All Rights Reserved. Permission to use, copy, modify, and
distribute this software and its documentation for educational,
research, and not-for-profit purposes, without fee and without a
signed licensing agreement, is hereby granted, provided that the
above copyright notice, this paragraph and the following two
paragraphs appear in all copies, modifications, and
distributions. Contact The Office of Technology Licensing, UC
Berkeley, 2150 Shattuck Avenue, Suite 510, Berkeley, CA 94720-1620,
(510) 643-7201, for commercial licensing opportunities.

IN NO EVENT SHALL REGENTS BE LIABLE TO ANY PARTY FOR DIRECT,
INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING
LOST PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS
DOCUMENTATION, EVEN IF REGENTS HAS BEEN ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.

REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE. THE SOFTWARE AND ACCOMPANYING
DOCUMENTATION, IF ANY, PROVIDED HEREUNDER IS PROVIDED "AS
IS". REGENTS HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT,
UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
*/

#ifndef SPARSE_SOLVER_HPP
#define SPARSE_SOLVER_HPP

#include <arcim/arcsim.hpp>
#include "sparse.hpp"
#include "vectors.hpp"
#include <Eigen/Sparse>

namespace arcsim {

    ARCSIM_API std::vector<double> eigen_linear_solve(const SpMat<double> &A,
                                           const std::vector<double> &b);

    template<int m>
    std::vector<Vec<m> > eigen_linear_solve
            (const SpMat<Mat<m, m> > &A, const std::vector<Vec<m> > &b);

    template<int m>
    Eigen::SparseMatrix<double> sparse_to_eigen(const SpMat<Mat<m, m> > &As_);

#ifndef BUILD_ARCSIM
    extern template ARCSIM_API vector<Vec3> eigen_linear_solve(const SpMat<Mat3x3>& A,
        const vector<Vec3>& b);
#endif
}
#endif
