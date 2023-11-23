/**
 * @file basics.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-08-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <cstdint>
#include <type_traits>

/// @brief Building Automation and Management Systems (BAMSs)
namespace bams
{

static_assert(std::is_same<std::uint8_t, unsigned char>::value);
static_assert(std::is_same<std::int8_t, char>::value);

enum class control_type
{
    heating_and_cooling,
    lighting,
    security,
    access_control,
    fire_and_life_security,
    elevators_escalators
};

enum class principal_services : std::uint8_t
{
    light_control,
    smode_control,
    indoor_environmental_quality_monitoring,
    water_management,
    energy_management,
    ventilation_fans,
    HVAC_maintenance_service,
    fire_detection_alarms,
    security_access_control,
    digital_video_monitoring,
    intrusion_detection,
    mechanical_maintenance,
    entreprise_systems_integration,
    on_site_technical_services
};

} // namespace bams
