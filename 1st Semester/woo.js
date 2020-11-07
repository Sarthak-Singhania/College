const WooCommerceRestApi = require("@woocommerce/woocommerce-rest-api").default;
// import WooCommerceRestApi from "@woocommerce/woocommerce-rest-api"; // Supports ESM

const WooCommerce = new WooCommerceRestApi({
    url: 'https://assemblagetheshop.com',
    consumerKey: 'ck_ac3d83313668fe0ec874310b6584940883067dc0',
    consumerSecret: 'cs_dc8d28364b2220ae1e9a39485f56ecf57add8acf',
    version: 'wc/v3'
});
WooCommerce.get("")
    .then((response) => {
        console.log(response.data);
    })
    .catch((error) => {
        console.log(error.response.data)
    })
