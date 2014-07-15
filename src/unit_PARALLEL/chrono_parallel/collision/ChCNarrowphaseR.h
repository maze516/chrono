#ifndef CHC_NARROWPHASE_R_H
#define CHC_NARROWPHASE_R_H

#include "chrono_parallel/collision/ChCNarrowphase.h"

namespace chrono {
namespace collision {


class CH_PARALLEL_API ChCNarrowphaseR : public ChCNarrowphase {
public:
  ChCNarrowphaseR() {}

  virtual void Process(ChParallelDataManager* data_container);

  virtual void Update(ChParallelDataManager* data_container)
  {
    //// TODO
  }

  // Primitive collision functions
  static __host__ __device__
  bool sphere_sphere(const real3& pos1, const real& radius1,
                     const real3& pos2, const real& radius2,
                     real3& norm, real& depth,
                     real3& pt1, real3& pt2,
                     real& eff_radius);

  static __host__ __device__
  bool capsule_sphere(const real3& pos1, const real4& rot1, const real& radius1, const real& hlen1,
                      const real3& pos2, const real& radius2,
                      real3& norm, real& depth,
                      real3& pt1, real3& pt2,
                      real& eff_radius);

  static __host__ __device__
  bool box_sphere(const real3& pos1, const real4& rot1, const real3& hdims1,
                  const real3& pos2, const real& radius2,
                  real3& norm, real& depth,
                  real3& pt1, real3& pt2,
                  real& eff_radius);

  static __host__ __device__
  bool face_sphere(const real3& A1, const real3& B1, const real3& C1,
                   const real3& pos2, const real& radius2,
                   real3& norm, real& depth,
                   real3& pt1, real3& pt2,
                   real& eff_radius);

  static __host__ __device__
  int capsule_capsule(const real3& pos1, const real4& rot1, const real& radius1, const real& hlen1,
                      const real3& pos2, const real4& rot2, const real& radius2, const real& hlen2,
                      real3* norm, real* depth,
                      real3* pt1, real3* pt2,
                      real* eff_radius);

  static __host__ __device__
  int box_capsule(const real3& pos1, const real4& rot1, const real3& hdims1,
                  const real3& pos2, const real4& rot2, const real& radius2, const real& hlen2,
                  real3* norm, real* depth,
                  real3* pt1, real3* pt2,
                  real* eff_radius);

  static __host__ __device__
  int box_box(const real3& pos1, const real4& rot1, const real3& hdims1,
              const real3& pos2, const real4& rot2, const real3& hdims2,
              real3* norm, real* depth,
              real3* pt1, real3* pt2,
              real* eff_radius);

private:
  void host_process(ChParallelDataManager* data_container,
                    uint                   num_potentialCollisions,
                    custom_vector<uint>&   contact_index,
                    custom_vector<uint>&   contact_flag);
  void host_count(ChParallelDataManager* data_container,
                    uint                   num_potentialCollisions,
                    custom_vector<uint>&   max_contacts);
};


} // end namespace collision
} // end namespace chrono


#endif

