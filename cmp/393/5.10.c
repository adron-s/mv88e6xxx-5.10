static const struct mv88e6xxx_ops mv88e6393x_ops = {
	/* MV88E6XXX_FAMILY_6393 */
	.setup_errata = mv88e6393x_serdes_setup_errata,
	.irl_init_all = mv88e6390_g2_irl_init_all,
	.get_eeprom = mv88e6xxx_g2_get_eeprom8,
	.set_eeprom = mv88e6xxx_g2_set_eeprom8,
	.set_switch_mac = mv88e6xxx_g2_set_switch_mac,
	.phy_read = mv88e6xxx_g2_smi_phy_read,
	.phy_write = mv88e6xxx_g2_smi_phy_write,
	.port_set_link = mv88e6xxx_port_set_link,
	.port_set_rgmii_delay = mv88e6390_port_set_rgmii_delay,
	.port_set_speed_duplex = mv88e6393x_port_set_speed_duplex,
	.port_max_speed_mode = mv88e6393x_port_max_speed_mode,
	.port_tag_remap = mv88e6390_port_tag_remap,
	.port_set_policy = mv88e6393x_port_set_policy,
	.port_set_frame_mode = mv88e6351_port_set_frame_mode,
	.port_set_egress_floods = mv88e6352_port_set_egress_floods,
	.port_set_ether_type = mv88e6393x_port_set_ether_type,
	.port_set_jumbo_size = mv88e6165_port_set_jumbo_size,
	.port_egress_rate_limiting = mv88e6097_port_egress_rate_limiting,
	.port_pause_limit = mv88e6390_port_pause_limit,
	.port_disable_learn_limit = mv88e6xxx_port_disable_learn_limit,
	.port_disable_pri_override = mv88e6xxx_port_disable_pri_override,
	.port_get_cmode = mv88e6352_port_get_cmode,
	.port_set_cmode = mv88e6393x_port_set_cmode,
	.port_setup_message_port = mv88e6xxx_setup_message_port,
	.port_set_upstream_port = mv88e6393x_port_set_upstream_port,
	.stats_snapshot = mv88e6390_g1_stats_snapshot,
	.stats_set_histogram = mv88e6390_g1_stats_set_histogram,
	.stats_get_sset_count = mv88e6320_stats_get_sset_count,
	.stats_get_strings = mv88e6320_stats_get_strings,
	.stats_get_stats = mv88e6390_stats_get_stats,
	/* .set_cpu_port is missing because this family does not support a global
	 * CPU port, only per port CPU port which is set via
	 * .port_set_upstream_port method.
	 */
	.set_egress_port = mv88e6393x_set_egress_port,
	.watchdog_ops = &mv88e6390_watchdog_ops,
	.mgmt_rsvd2cpu = mv88e6393x_port_mgmt_rsvd2cpu,
	.pot_clear = mv88e6xxx_g2_pot_clear,
	.reset = mv88e6352_g1_reset,
	.rmu_disable = mv88e6390_g1_rmu_disable,
	.atu_get_hash = mv88e6165_g1_atu_get_hash,
	.atu_set_hash = mv88e6165_g1_atu_set_hash,
	.vtu_getnext = mv88e6390_g1_vtu_getnext,
	.vtu_loadpurge = mv88e6390_g1_vtu_loadpurge,
	.serdes_power = mv88e6393x_serdes_power,
	.serdes_get_lane = mv88e6393x_serdes_get_lane,
	.serdes_pcs_get_state = mv88e6393x_serdes_pcs_get_state,
	.serdes_pcs_config = mv88e6390_serdes_pcs_config,
	.serdes_pcs_an_restart = mv88e6390_serdes_pcs_an_restart,
	.serdes_pcs_link_up = mv88e6390_serdes_pcs_link_up,
	.serdes_irq_mapping = mv88e6390_serdes_irq_mapping,
	.serdes_irq_enable = mv88e6393x_serdes_irq_enable,
	.serdes_irq_status = mv88e6393x_serdes_irq_status,
	/* TODO: serdes stats */
	.gpio_ops = &mv88e6352_gpio_ops,
	.avb_ops = &mv88e6390_avb_ops,
	.ptp_ops = &mv88e6352_ptp_ops,
	.phylink_validate = mv88e6393x_phylink_validate,
};

	[MV88E6393X] = {
		.prod_num = MV88E6XXX_PORT_SWITCH_ID_PROD_6393X,
		.family = MV88E6XXX_FAMILY_6393,
		.name = "Marvell 88E6393X",
		.num_databases = 4096,
		.num_ports = 11,	/* 10 + Z80 */
		.num_internal_phys = 9,
		.max_vid = 8191,
		.port_base_addr = 0x0,
		.phy_base_addr = 0x0,
		.global1_addr = 0x1b,
		.global2_addr = 0x1c,
		.age_time_coeff = 3750,
		.g1_irqs = 10,
		.g2_irqs = 14,
		.atu_move_port_mask = 0x1f,
		.pvt = true,
		.multi_chip = true,
		.tag_protocol = DSA_TAG_PROTO_DSA,
		.ptp_support = true,
		.ops = &mv88e6393x_ops,
	},
