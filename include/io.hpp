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

#ifndef IO_HPP
#define IO_HPP

#include <arcsim/arcsim.hpp>

#include "mesh.hpp"

namespace arcsim {
    std::vector<Face *> ARCSIM_API triangulate(const std::vector<Vert *> &verts);

    void ARCSIM_API triangle_to_obj(const std::string &infile, const std::string &outfile);

    void ARCSIM_API load_obj(Mesh &mesh, const std::string &filename);

    void ARCSIM_API load_objs(std::vector<Mesh *> &meshes, const std::string &prefix);

    void ARCSIM_API load_obs_frames(vector<Mesh> &meshes, const string &prefix, const int frameStart, const int frameEnd);

    void ARCSIM_API save_obj(const Mesh &mesh, const std::string &filename);

    void ARCSIM_API save_objs(const std::vector<Mesh *> &meshes, const std::string &prefix);

    void ARCSIM_API load_vdb(const std::string &filename);

    void ARCSIM_API save_vdb(const std::string &filename);

    void ARCSIM_API save_transformation(const Transformation &tr,
                             const std::string &filename);

#ifdef ARCSIM_WITH_PNG
// w_crop and h_crop specify a multiplicative crop window
    void ARCSIM_API save_screenshot(const std::string &filename);
#endif

#ifdef ARCSIM_WITH_BOOST
// check that output directory exists; if not, create it
    void ARCSIM_API ensure_existing_directory(const std::string &path);

    void ARCSIM_API copy_file(const string &input, const string &output);
#endif

}
#endif
