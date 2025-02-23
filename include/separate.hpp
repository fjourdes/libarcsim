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

#ifndef SEPARATE_HPP
#define SEPARATE_HPP

#include <arcim/arcsim.hpp>
#include "mesh.hpp"
#include "collisionutil.hpp"

namespace arcsim {
    ARCSIM_API void init_meshes(std::vector<Mesh *> &meshes, const std::vector<Mesh *> &old_meshes,
                     const std::vector<Mesh *> &obs_meshes);

    ARCSIM_API bool
    has_intersection(const std::vector<Face *> &added_faces, Mesh *mesh, const std::vector<AccelStruct *> &obs_accs);

    ARCSIM_API void separate(std::vector<Mesh *> &meshes, const std::vector<Mesh *> &old_meshes,
                  const std::vector<Mesh *> &obs_meshes);

    ARCSIM_API void ICM_separate(std::vector<Mesh *> &meshes, const std::vector<Mesh *> &old_meshes,
                      const std::vector<Mesh *> &obs_meshes, bool log = true);

    ARCSIM_API int intersection_number(const vector<AccelStruct *> &accs,
                            const vector<AccelStruct *> &obs_accs);
}
#endif
