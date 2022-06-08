def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.


# Press the green button in the gutter to run the script.
if _name_ == '_main_':
    print_hi('PyCharm')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
const LOCALSTORAGE_ACCESS_TOKEN_KEY = 'spotify-audio-analysis-playback-token';
const LOCALSTORAGE_ACCESS_TOKEN_EXPIRY_KEY = 'spotify-audio-analysis-playback-token-expires-in';

function goPython(){
  $.ajax({
    url: "spoti.py",
   context: document.body
  }).done(function() {
   alert('finished python script');;
  });
}

function parseHash(hash) {
  return hash
    .substring(1)
    .split('&')
    .reduce(function (initial, item) {
      if (item) {
        var parts = item.split('=');
        initial[parts[0]] = decodeURIComponent(parts[1]);
      }
      return initial;
    }, {});
}

document.addEventListener('DOMContentLoaded', () => {
  if (localStorage.getItem(LOCALSTORAGE_ACCESS_TOKEN_KEY) &&
      parseInt(parseInt(localStorage.getItem(LOCALSTORAGE_ACCESS_TOKEN_EXPIRY_KEY))) > Date.now()) {
    window.location = "/about.html";
  } else {
    if(window.location.hash) {
      const hash = parseHash(window.location.hash);
      if (hash['access_token'] &&
          hash['expires_in']) {
        localStorage.setItem(LOCALSTORAGE_ACCESS_TOKEN_KEY, hash['access_token']);
        localStorage.setItem(LOCALSTORAGE_ACCESS_TOKEN_EXPIRY_KEY, Date.now() + 990 * parseInt(hash['expires_in']));
        window.location = "/about.html";
      }
    }
    document.getElementById('login').addEventListener('click', function(e) {
      e.preventDefault();
      fetch('/spotifyRedirectUri')
      .then(e => e.json())
      .then(data => {
        window.location = data.redirectUri;
      })
      .catch(error => { alert("Failed to prepare for Spotify Authentication")});
    });
  }
})