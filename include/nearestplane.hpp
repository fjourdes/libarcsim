#ifndef NEARESTPLANE_HPP
#define NEARESTPLANE_HPP

#include <arcsim/arcsim.hpp>
#include "mesh.hpp"

namespace arcsim {
	typedef pair<Vec3, Vec3> TangentialPlane;

	struct ARCSIM_API CuttingPlane {
		Vec3 pos;
		vector<Vec3> directions;
	};
	typedef vector<CuttingPlane> CuttingPlanes;

	struct ARCSIM_API CuttingPlaneSet {
		vector<CuttingPlanes> nodePlanes;
		vector<CuttingPlanes> edgePlanes;
		vector<CuttingPlanes> facePlanes;
	};

	class ARCSIM_API NearestSearch {
	private:

	public:
		NearestSearch() {};

		~NearestSearch() {};

		vector<TangentialPlane> getNearestPlanes(const vector<Mesh *> &meshes, const vector<Mesh *> &obs_meshes);

		CuttingPlaneSet getCuttingPlanes(const vector<Mesh *> &meshes, const vector<Mesh *> &obs_meshes);

		static void findProximities(const Face *face0, const Face *face1);

		static void findCloseFaces(const Face *face0, const Face *face1);

	};
}
#endif