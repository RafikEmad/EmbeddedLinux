#!/bin/bash

unit_description=""

# Function to create unit file
create_unit_file() {
    unit_description=$1
    echo "Creating systemd unit file..."
    cat <<EOF > /etc/systemd/system/example.service
[Unit]
Description=${unit_description}
EOF
    echo "Unit file created with description: ${unit_description}"
}

# Function to append additional unit file fields
append_unit_file() {
    local field_name=$1
    local field_data=$2
    echo "Appending $field_name to systemd unit file..."
    echo "${field_name}=${field_data}" >> /etc/systemd/system/example.service
    echo "Appended ${field_name}: ${field_data}"
}

# Function to append service details to the unit file
append_service_to_unit_file() {
    echo "Appending service details to systemd unit file..."
    cat <<EOF >> /etc/systemd/system/example.service

[Service]
Environment=${environment_value}
Type=${service_type}
ExecStart=${exec_start}
User=${service_user}
Group=${service_group}
Restart=${service_restart}

EOF
    echo "Service details appended to the unit file."
}

# Function to append service details to the unit file
append_install_to_unit_file() {
    echo "Appending install details to systemd unit file..."
    cat <<EOF >> /etc/systemd/system/example.service

[Install]
WantedBy=${service_wanted_by}
EOF
    echo "install details appended to the unit file."
}

# Function to create service file
create_service_file() {
    local service_type
    local exec_start
    local service_description
    local service_user
    local service_group
    local service_restart
    local environment_value


    while true; do
        echo "Creating systemd service file..."
        select service_option in "Service Type" "ExecStart" "Description" "User" "Group" "Restart" "Environment" "Done"; do
            case $service_option in
                "Service Type")
                    read -p "Enter service type (simple/forking/oneshot/dbus/notify/idle): " service_type
                    ;;
                "ExecStart")
                    read -p "Enter path of ExecStart: " exec_start
                    ;;
                "Description")
                    read -p "Enter description for the service: " service_description
                    ;;
                "User")
                    read -p "Enter the user for the service: " service_user
                    ;;
                "Group")
                    read -p "Enter the group for the service: " service_group
                    ;;
                "Restart")
                    read -p "Enter restart policy for the service (always/on-failure/on-abort/...): " service_restart
                    ;;
                "Environment")
                    read -p "Enter the environment for the service: " environment_value
                    ;;
                "Done")
                    append_service_to_unit_file
                    return
                    ;;
                *)
                    echo "Invalid option."
                    ;;
            esac
        done
    done
}

# Function to install service
install_service() {
    local service_wanted_by
    while true; do
            echo "Creating install section in service file..."
            select install_option in "WantedBy" "Done"; do
                case $install_option in
                    "WantedBy")
                        read -p "Enter 'WantedBy' target for the service (multi-user.target/graphical.target/...): " service_wanted_by
                        ;;
                    "Done")
                        append_install_to_unit_file
                        return
                        ;;
                    *)
                        echo "Invalid option."
                        ;;
                esac
            done
        done
    }

while true; do
    select val in "units" "service" "install" "exit"; do 
        case $val in 
            units)
                select unit_option in "description" "documents" "others"; do
                    case $unit_option in 
                        description)
                            read -p "Enter description for the unit: " description
                            create_unit_file "$description"
                            ;;
                        documents)
                            read -p "Enter field name: " field_name
                            read -p "Enter data for ${field_name}: " field_data
                            append_unit_file "$field_name" "$field_data"
                            ;;
                        others)
                            echo "Work on others..."
                            # Implement your logic for other unit options
                            ;;
                        *)
                            echo "Invalid option."
                            ;;
                    esac
                    break
                done
                ;;
            service)
                create_service_file
                ;;
            install)
                install_service
                ;;
            exit)
                echo "Exiting..."
                exit 0
                ;;
            *)
                echo "Invalid option."
                ;;
        esac
        break
    done
done
