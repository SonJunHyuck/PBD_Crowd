#include "group.h"
#include "agent.h"

Group::Group(uint16_t InGroupId, uint32_t InGenerateAgent)
{
    Id = InGroupId;

    Init();
}

Group::~Group()
{

}

void Group::Init()
{
    // Generate Particle;
    

    // Generate + Init SRD
    uint32_t AgentCounter = 0;
    auto(auto agent : Agents)
    {
        glm::vec3 SRDpos = agent.Position;
        agent.SRD = SRDpos;
        SRDs.emplace({ AgentCounter, SRDpos });
        AgentCounter++;
    }
}

void Group::UpdateSRDs()
{
    for(glm::vec3& SRD : SRDs)
    {
        SRD += Velocity;
    }
}

void Group::FollowPath()
{
    glm::vec3 CurrentWaypointPos = Path[CurrentWaypointId].Position;
    Velocity = CurrentWaypointPos - Position;
    float Distance = glm::length(Velocity);
    
    if(Distance != 0)
    {
        float PreferedVelocity = Distance > DefinedAccel ? DefinedAccel : Distance;

        Velocity /= Distance;  // Normalize;
        velocity *= PreferedVelocity * DeltaTime;

        UpdateSRDs();

        Position += Velocity;
    }

    float DensityWeight = 0.2f
    if(Distance < Density - DensityWeight)
    {
        if(CurrentWaypointId < Path.size() - 1)
            CurrentWaypointId++;
    }
}