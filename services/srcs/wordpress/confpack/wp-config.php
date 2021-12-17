<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'cbilbo' );

/** MySQL database password */
define( 'DB_PASSWORD', 'cbilbo' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql:3306' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         ',uxSAoL#D1_*Domrx/$=KpGQSHsCgec2l?ZQ)PVLXT|:-Q7+>8fN9DWt$UeDy]@.');
define('SECURE_AUTH_KEY',  ':1-Izl>O>5sH;d,R+6N|qqe3U!N!N-SsH^:W]`T [Zp3Hb^Ub|YA4 p:0O/v|M_]');
define('LOGGED_IN_KEY',    'ZBd{&,>^@gm05&]-2:_~7Ce@2lHo&Yk+tp<W~)KikDo*dtK8.<OU<`S5EG.[bT]k');
define('NONCE_KEY',        'zNRkDXw}^.>:EXjUY<=@oH,YFMb#b(yH&+7mrF`,(!vv:-N +|3uRrNOTF(,nK0V');
define('AUTH_SALT',        '~D:4ECx5pdaZ$K0p|QV1a%NtG4qj}x%7|r!BD!V>/~G98pm^X)1#`a,~v^P+@UOe');
define('SECURE_AUTH_SALT', 'pHX^uS]Ji:W-DA|^&$;-68f=Mwt;-Bu@YVTY[ rS+YC3gg$vocS8+|JR~|~sTQ+3');
define('LOGGED_IN_SALT',   'm;?xB7to[}X+::)N}N h43(V+3[s{<rfN5D@?[SG+;7pm|+fatkM9A;bxw:,-ka1');
define('NONCE_SALT',       'HI]ST+`+`PnVo0dXb-r[Bb%1&)&,PH~j.|1MQ4pnjo?r)d^cwN^P7m$87u[u21-9');

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';