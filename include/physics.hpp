/*
  Copyright ©2013 The Regents of the University of California
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

#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include <arcsim/arcsim.hpp>
#include "cloth.hpp"
#include "geometry.hpp"
#include "simulation.hpp"
#include <vector>
#include "collision.hpp"

namespace arcsim {

    struct ARCSIM_API ForceCollection {
        Vec3 stretchForce;
        Vec3 bendingForce;
    };

	template<Space s>
	double internal_energy(const Cloth &cloth);

	template<Space s>
	double internal_energy(const std::vector<Face *> &faces, const std::vector<Edge *> &edges);

#ifndef BUILD_ARCSIM
	extern template ARCSIM_API double internal_energy<PS>(const std::vector<Face*>&, const std::vector<Edge*>&);

	extern template ARCSIM_API double internal_energy<WS>(const std::vector<Face*>&, const std::vector<Edge*>&);

	extern template ARCSIM_API double internal_energy<PS>(const Cloth&);

	extern template ARCSIM_API double internal_energy<WS>(const Cloth&);
#endif 

	ARCSIM_API double constraint_energy(const std::vector<Constraint *> &cons);

	ARCSIM_API double external_energy(const Cloth &cloth, const Vec3 &gravity,
						   const Wind &wind);

// A += dt^2 dF/dx; b += dt F + dt^2 dF/dx v
// also adds damping terms
// if dt == 0, just does A += dF/dx; b += F instead, no damping
	template<Space s>
	void add_internal_forces(const Cloth &cloth, SpMat<Mat3x3> &A,
							 std::vector<Vec3> &b, double dt);

	template<Space s>
	void add_internal_forces(const std::vector<Face *> &faces,
							 const std::vector<Edge *> &edges,
							 SpMat<Mat3x3> &A, std::vector<Vec3> &b, double dt);

	template<Space s>
	void add_internal_forces(const Cloth &cloth, vector<Vec3> &forceVec);

#ifndef BUILD_ARCSIM
	extern template ARCSIM_API void add_internal_forces<PS>(const std::vector<Face*>&,
		const std::vector<Edge*>&,
		SpMat<Mat3x3>&, std::vector<Vec3>&,
		double);

	extern template ARCSIM_API void add_internal_forces<WS>(const std::vector<Face*>&,
		const std::vector<Edge*>&,
		SpMat<Mat3x3>&, std::vector<Vec3>&,
		double);

	extern template ARCSIM_API void add_internal_forces<PS>(const Cloth&, SpMat<Mat3x3>&,
		vector<Vec3>&, double);

	extern template ARCSIM_API void add_internal_forces<WS>(const Cloth&, SpMat<Mat3x3>&,
		vector<Vec3>&, double);
#endif

	ARCSIM_API void add_constraint_forces(const Cloth &cloth,
							   const std::vector<Constraint *> &cons,
							   SpMat<Mat3x3> &A, std::vector<Vec3> &b, double dt);

	ARCSIM_API void add_external_forces(const Cloth &cloth, const Vec3 &gravity,
							 const Wind &wind, std::vector<Vec3> &fext,
							 std::vector<Mat3x3> &Jext);

	ARCSIM_API void add_morph_forces(const Cloth &cloth, const Morph &morph, double t,
						  double dt,
						  std::vector<Vec3> &fext, std::vector<Mat3x3> &Jext);

	ARCSIM_API void explicit_update(Cloth &cloth, const std::vector<Vec3> &fext,
						 const std::vector<Constraint *> &cons, double dt,
						 bool update_positions = true);


	ARCSIM_API pair<SpMat<Mat3x3>, vector<Vec3> > obtain_implicit_equation(Cloth &cloth, const vector<Vec3> &fext,
																const vector<Mat3x3> &Jext,
																const vector<Constraint *> &cons, double dt, ForceCollection forces = ForceCollection());

	ARCSIM_API void update(Cloth &cloth, vector<pair<Vec3, Vec3> > v_and_r, double dt,
				bool update_positions = true,
				bool update_velocities = true);
}
#endif
