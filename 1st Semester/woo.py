from woocommerce import API

wcapi = API(
    url="https://assemblagetheshop.com",
    consumer_key="ck_ac3d83313668fe0ec874310b6584940883067dc0",
    consumer_secret="cs_dc8d28364b2220ae1e9a39485f56ecf57add8acf",
    wp_api=True,
    version="wc/v3"
)

print(wcapi.get('orders').json())